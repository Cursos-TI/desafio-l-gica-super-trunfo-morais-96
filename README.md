# Super Trunfo em C - Atributos Aleatórios

Este projeto é uma implementação do jogo **Super Trunfo**, desenvolvido em linguagem C. Nele, o jogador compara **duas cartas de países** com base em **dois atributos numéricos**, seguindo regras específicas para cada um.

Todos os atributos das cartas são **gerados aleatoriamente** a cada execução do jogo, o que garante partidas diferentes sempre.

---

## 🧠 Atributos disponíveis

Cada país possui os seguintes atributos:

| Código | Atributo               | Tipo   | Regra de comparação           |
|--------|------------------------|--------|-------------------------------|
| 1      | População              | int    | Maior vence                   |
| 2      | Área (km²)             | float  | Maior vence                   |
| 3      | PIB (trilhões)         | float  | Maior vence                   |
| 4      | Pontos Turísticos      | int    | Maior vence                   |
| 5      | Densidade Demográfica  | float  | **Menor vence** (regra inversa)

---

## 🎮 Como funciona o jogo

1. O programa gera **automaticamente duas cartas** com dados aleatórios para os países "Brasil" e "Alemanha".
2. O jogador escolhe **dois atributos diferentes** para fazer a comparação.
3. O jogo compara os dois atributos individualmente:
   - Atribui um ponto ao país que tiver vantagem em cada atributo.
4. Soma os valores dos dois atributos de cada país.
5. Vence quem tiver a **maior soma total**.
6. Em caso de soma igual, o jogo exibe `"Empate!"`.

---

## 💻 Exemplo de execução

```txt
===== SUPER TRUNFO FINAL =====
Escolha o primeiro atributo para comparar:
1 - População
2 - Área
3 - PIB
4 - Pontos Turísticos
5 - Densidade Demográfica
Digite sua opção: 3

Escolha o segundo atributo para comparar (diferente do primeiro):
1 - População
2 - Área
4 - Pontos Turísticos
5 - Densidade Demográfica
Digite sua opção: 5

--- COMPARAÇÃO DE CARTAS ---
País 1: Brasil
País 2: Alemanha

Atributo 1: PIB
Brasil: 7.20
Alemanha: 15.30

Atributo 2: Densidade Demográfica
Brasil: 120.00
Alemanha: 300.00

Soma dos atributos:
Brasil: 127.20
Alemanha: 315.30

Resultado final: Alemanha venceu a rodada!