#include <stdio.h>
#include <locale.h>

typedef struct{
	int hora;
	int minutos;
} tempo;

tempo func(int num, tempo t){
	int total_minutos = t.hora * 60 + t.minutos + num;
	t.hora = total_minutos / 60;
	t.minutos = total_minutos % 60;
	return t;
}


int main(){
	int horas, minutos, minutos_extra;
	setlocale(LC_ALL, "Portuguese");
	printf("Digite o hor�rio atual [HH:mm]: ");
	scanf("%d:%d", &horas, &minutos);
	printf("Digite a quantidade de minutos para ser adicionado: ");
	scanf("%d", &minutos_extra);
	
	tempo atual;
	
	atual.hora = horas;
	atual.minutos = minutos;
	
	tempo horario_final = func(minutos_extra, atual);
	printf("%02d:%02d", horario_final.hora, horario_final.minutos);
}
