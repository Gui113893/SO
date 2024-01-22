# TESTES
### DIFERENTE NÚMERO DE TABLES

É possível rodar o programa com a variável `NUMTABLES`, do ficheiro `/src/probConst.h`, com um valor qualquer, no entanto,
este problema, em específico, é desenhado para funcionar só com 2 mesas, ou seja, só funciona adicionar mais mesas, se
os valores dos grupos no ficheiro `/run/config.txt` forem todos diferentes. 

### DIFERENTE NÚMERO DE GRUPOS

Para adicionar mais grupos ao output, é preciso ter em atenção o que foi referido no tópico anterior pois, sim é possível
adicionar mais grupos ao ficheiro `/run/config.txt`, no entanto:

- se existirem mais que 2 mesas em `NUMTABLES`, o grupo adicionado tem de ter valores diferentes dos já presentes;
- se existirem só 2 mesas, o grupo adicionado pode ter qualquer valor

### CONCLUSÃO

É possível rodar o programa com um número qualquer de grupos, desde que não ultrapassem o valor da variável `MAXGROUPS` do ficheiro
`/src/probConst.h`, no entanto, o seus valores associados devem ter especial atenção caso o valor de `NUMTABLES` seja diferente de 2

