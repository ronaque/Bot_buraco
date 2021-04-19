all: meu_bot.c func.o descarte.o puxe.o
  gcc meu_bot.c func.o descarte.o puxe.o -o meu_bot -g -w
func.o: func.c
  gcc func.c -c -g -w
descarte.o: descarte.c
  gcc descarte.c -c -g -w
puxe.o: puxe.c
  gcc puxe.c -c -g -w