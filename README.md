*Este projeto foi criado como parte do currículo da 42 por vde-alme.*

# ft_printf

## Descrição

`ft_printf` é uma reimplementação da função `printf()` da biblioteca padrão do C. O objetivo é compreender o funcionamento das funções variádicas em C e construir do zero uma biblioteca de formatação robusta e extensível.

A biblioteca é compilada em um arquivo estático (`libftprintf.a`) e suporta todas as conversões obrigatórias, além do conjunto completo de flags do bônus.

### Conversões suportadas

| Especificador | Descrição |
|---------------|-----------|
| `%c` | Imprime um único caractere |
| `%s` | Imprime uma string |
| `%p` | Imprime o endereço de um ponteiro em hexadecimal |
| `%d` / `%i` | Imprime um inteiro decimal com sinal |
| `%u` | Imprime um inteiro decimal sem sinal |
| `%x` / `%X` | Imprime um inteiro em hexadecimal (minúsculo/maiúsculo) |
| `%%` | Imprime um sinal de porcentagem literal |

### Flags suportadas (bônus)

| Flag | Descrição |
|------|-----------|
| `-` | Alinha a saída à esquerda dentro da largura do campo |
| `0` | Preenche com zeros em vez de espaços |
| `.` | Precisão — limita dígitos para números, caracteres para strings |
| `width` | Largura mínima do campo |
| `#` | Adiciona prefixo `0x` / `0X` para hexadecimal |
| `+` | Sempre imprime o sinal para inteiros |
| ` ` (espaço) | Imprime um espaço antes de inteiros positivos |

---

## Algoritmo e Estrutura de Dados

### Struct `t_flags`

Todas as flags de formato extraídas de um especificador `%...` são armazenadas em uma única estrutura `t_flags`:

```c
typedef struct s_flags
{
    int     dash;
    int     zero;
    int     dot;
    int     width;
    int     precision;
    int     hash;
    int     space;
    int     plus;
    char    type;
} t_flags;
```

Essa escolha mantém todo o contexto de uma conversão em um único lugar, facilitando o repasse para os handlers individuais sem uma lista longa de parâmetros. Cada campo corresponde diretamente a uma flag ou valor do especificador de formato.

### Pipeline de parsing

Quando `ft_printf` encontra um `%`, chama `ft_parse_flags`, que percorre os caracteres um a um e preenche a struct `t_flags` antes de despachar para `ft_processor`. O parser trata as flags (`-`, `0`, `#`, ` `, `+`), em seguida os campos numéricos de largura e precisão (via `ft_parse_digits`) e, por fim, o caractere de conversão.

A função `ft_parse_digits` lê a sequência de dígitos e atribui o valor a `flags->width` ou `flags->precision` dependendo se um `.` já foi encontrado — uma forma limpa de tratar ambos os campos com uma única função.

### Dispatch

`ft_processor` funciona como um roteador: lê `flags->type` e chama o handler adequado (`ft_handle_char`, `ft_handle_str`, `ft_handle_int`, `ft_handle_uint`, `ft_handle_hex`, `ft_handle_ptr`). Isso mantém cada conversão isolada e facilita manutenção e extensão.

### Lógica de preenchimento (padding)

`ft_print_pad(total_width, len, has_zero)` é um utilitário único que trata tanto o preenchimento com zeros quanto com espaços, usado de forma uniforme em todos os handlers. O padding é aplicado antes ou depois do valor dependendo da flag `-`.

Para inteiros e valores hexadecimais, o prefixo (sinal, `+`, ` `, `0x`, `0X`) é impresso entre o espaço à esquerda e o zero de preenchimento, reproduzindo corretamente o comportamento do `printf` original.

---

## Instruções

### Compilação

```bash
make        # compila a libftprintf.a
make bonus  # mesmo alvo (bônus integrado à compilação principal)
make clean  # remove os arquivos objeto
make fclean # remove os arquivos objeto e a biblioteca
make re     # recompilação completa
```

### Uso

Inclua o header e vincule a biblioteca ao compilar seu projeto:

```c
#include "ft_printf_bonus.h"

int main(void)
{
    ft_printf("Olá, %s! Você tem %d anos.\n", "mundo", 42);
    ft_printf("Hex: %#010x\n", 255);
    ft_printf("Ponteiro: %p\n", (void *)main);
    return (0);
}
```

```bash
cc main.c libftprintf.a -o meu_programa
```

---

## Recursos

- [printf(3) — man page Linux](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Funções variádicas em C — cppreference](https://en.cppreference.com/w/c/variadic)
- [Especificação POSIX do printf](https://pubs.opengroup.org/onlinepubs/9699919799/functions/printf.html)
- [42 Docs — dicas sobre ft_printf](https://harm-smits.github.io/42docs/projects/ft_printf)

### Uso de IA

O Claude (claude.ai) foi utilizado para gerar este arquivo README com base nos requisitos do subject e no código-fonte do projeto. Nenhuma IA foi utilizada na escrita, no design ou na depuração dos arquivos-fonte em C.
