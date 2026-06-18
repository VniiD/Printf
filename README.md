*Este projeto foi criado como parte do currículo da 42 por \<vde-alme>.*

---

# ft\_printf

Reimplementação da função `printf` da biblioteca `libc`, com suporte completo aos especificadores de conversão obrigatórios e à parte bônus com flags de formatação.

---

## Descrição

O `ft_printf` reproduz o comportamento essencial da `printf` padrão do C, aceitando uma string de formato com especificadores (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`) e um número variável de argumentos adicionais. A versão bônus estende esse suporte com flags de alinhamento e precisão (`-`, `0`, `.`, `#`, `+`, espaço) e largura mínima de campo.

### Arquitetura

**Gestão de Variádicos**
A função usa as macros de `stdarg.h` (`va_start`, `va_arg`, `va_end`) para percorrer os argumentos variádicos em conformidade com a ABI System V, lendo argumentos diretamente do frame de chamada sem copiar toda a lista.

**Estrutura de Flags (Bônus)**
A parte bônus usa a `struct t_flags` (definida em `ft_printf_bonus.h`) para transportar o estado das flags entre as funções de parsing e impressão. Essa abordagem permite passar o contexto de formatação em um único argumento — respeitando o limite de 25 linhas da Norminette — em vez de usar múltiplos parâmetros ou variáveis globais.

```c
typedef struct s_flags
{
    int minus;
    int zero;
    int dot;
    int precision;
    int width;
    int hash;
    int space;
    int plus;
}   t_flags;
```

**Criação da biblioteca estática**
A compilação gera `libftprintf.a` via `ar rcs`, sem depender de `libft` externa. Isso cria uma biblioteca estática com índice de símbolos, linkável diretamente em projetos C.

---

## Flags suportadas

| Parte        | Especificadores / Flags                          |
|-------------|--------------------------------------------------|
| Mandatório  | `%c` `%s` `%p` `%d` `%i` `%u` `%x` `%X` `%%`   |
| Bônus       | `-` `0` `.` `#` `+` ` ` (espaço) · largura de campo |

---

## Estrutura de arquivos

```
ft_printf/
├── Makefile
├── ft_printf.h              # Protótipos da parte mandatória
├── ft_printf.c              # Entry point: loop de formato + dispatch
├── ft_print_hex.c           # Impressão hexadecimal (%x, %X, %p)
├── ft_print_utils.c         # ft_print_char, str, nbr, unsigned, percent
├── ft_printf_bonus.h        # Struct t_flags + protótipos do bônus
├── ft_printf_bonus.c        # Parsing de flags/largura/precisão + dispatch
├── ft_print_hex_bonus.c     # Hex com suporte a flags (#, zero-pad, width)
├── ft_print_nbr_bonus.c     # Inteiros com suporte a +, espaço, precisão
└── ft_print_utils_bonus.c   # char, str, pad com suporte total a flags
```

---

## Instruções

### Compilação

**Parte mandatória:**
```bash
make
# Gera: libftprintf.a
```

**Parte bônus:**
```bash
make bonus
# Gera: libftprintf.a com suporte a flags
```

**Limpar objetos:**
```bash
make clean   # remove .o
make fclean  # remove .o e libftprintf.a
make re      # fclean + all
```

### Uso em projetos

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Inteiro: %d | Hex: %#010x | String: %-20s\n", 42, 255, "olá");
    return (0);
}
```

Compilar com a biblioteca:
```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o programa
```

---

## Algoritmo e decisões técnicas

### Parte mandatória — loop de formato simples

O `ft_printf` percorre a string de formato caractere por caractere. Ao encontrar `%`, avança uma posição e despacha para a função correspondente com base no especificador:

```
ft_printf("formato", ...) 
  └─ loop sobre format[i]
       ├─ format[i] != '%' → write(1, &format[i], 1)
       └─ format[i] == '%' → ft_formats(args, format[i+1])
            ├─ 'c' → ft_print_char
            ├─ 's' → ft_print_str
            ├─ 'p' → ft_print_ptr
            ├─ 'd'/'i' → ft_print_nbr
            ├─ 'u' → ft_print_unsigned
            ├─ 'x'/'X' → ft_print_hex
            └─ '%' → ft_print_percent
```

Cada função de impressão retorna o número de bytes escritos, que é acumulado no `print_length` retornado pelo `ft_printf`.

### Parte bônus — parsing de flags em duas etapas

O bônus adiciona duas etapas de parsing antes do despacho:

1. **`parse_flags`**: percorre os caracteres de flag (`-`, `0`, `#`, ` `, `+`) e preenche os campos correspondentes na `t_flags`.
2. **`parse_width_prec`**: lê os dígitos de largura (width) e, se presente, o `.` seguido dos dígitos de precisão.

```
'%' encontrado
  ├─ parse_flags   → preenche flags.minus, .zero, .hash, .space, .plus
  ├─ parse_width_prec → preenche flags.width, .dot, .precision
  └─ ft_formats_bonus(args, format[i], flags)
```

### Impressão com padding

As funções de impressão seguem o padrão:

```
1. calcular len  (tamanho real do conteúdo)
2. calcular z    (zeros de precisão ou zero-padding)
3. calcular s    (espaços de alinhamento: width - len - z - sinal)
4. se !minus → imprimir s espaços
5. imprimir sinal / prefixo (0x, +, espaço)
6. imprimir z zeros
7. imprimir conteúdo
8. se minus  → imprimir s espaços
```

Essa ordem garante compatibilidade com o comportamento da `printf` original nos casos de alinhamento à esquerda vs direita, zero-padding com precisão e prefixos hexadecimais.

---

## Recursos

### Documentação oficial
- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html) — especificação completa do formato
- [man 3 stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html) — macros de argumentos variádicos
- [cppreference — printf](https://en.cppreference.com/w/c/io/fprintf) — referência com exemplos

### Uso de IA neste projeto
A IA foi utilizada para:
- Verificar edge cases nos especificadores `%p` (ponteiro nulo → `(nil)`) e `%s` (string nula → `(null)`)
- Revisar a lógica de cálculo de `s` (espaços) quando `precision` e `width` interagem simultaneamente
