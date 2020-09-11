#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <algorithm>
#include <vector>

using namespace std;

struct process
{
	string name;
  int processTime;
	int arrivalTime;
	int creationTime;
	int finalizationTime;
  int turnAround;
};


int main(){


	int numberOfProcess = 0;
	int quantum = 0;
	int actualNumberProcess = 0;
	int averageTournaround = 0;

	cout << "Digite a quantidade de processos que deseja fazer o Round Robin" << endl;
	cin >> numberOfProcess;

	actualNumberProcess = numberOfProcess;
	process processObject[numberOfProcess];



	for(int i=0; i < numberOfProcess; i++){
		cout << "Por favor, digite o nome do processo:" << endl;
		cin >> processObject[i].name;

		cout << "Por favor, digite o tempo de processamento:" << endl;
		cin >> processObject[i].processTime;

		cout << "Por favor, digite o tempo de cria��os:" << endl;
		cin >> processObject[i].creationTime;

		processObject[i].arrivalTime = processObject[i].creationTime;
	}

	cout << "Digite o valor do Quantum" << endl;
	cin >> quantum;

	int countProcess = 0;
	int processControl = countProcess;
	int i = 0;
	int cicleTime = 0;
	int value;
	bool activate = true;
	int ableQueue = 0;
	int averageTurnaround = 0;


	while(numberOfProcess != 0) {

		if(processObject[i].creationTime > cicleTime)
		{
			do
			{
				if(processObject[i].creationTime > 0)
				{
					cicleTime += quantum;
					activate = false;

				}
			}
			while(processObject[i].creationTime > cicleTime);
		}

		if(processObject[i].creationTime == cicleTime) //verifica se o processo ja chegou, s eo tempo de cria��o dele for menor q o tempo atual do ciclo
		{
			cout << "\n\nCiclo " << cicleTime << " -- \n";
			cout << processObject[i].name << " entrou na fila de aptos!\n";
		}




		if(processObject[i].processTime > quantum)
		{


			if(processObject[i].arrivalTime <= cicleTime && processObject[i].arrivalTime != 0 && activate == false )
			{
				cicleTime = processObject[i].arrivalTime;
				processObject[i].arrivalTime = 0;

				activate = true;

			}



			cout << "\n\nCiclo " << cicleTime << " -- \n";

			processObject[i].processTime = processObject[i].processTime - quantum;
			cout << "Executando: " << processObject[i].name;
			cicleTime += quantum;
			cout << "\nTempo: " << cicleTime <<endl;

			cout << "\nFila de aptos";
			ableQueue = (numberOfProcess - i);
			if((i + 1) >= numberOfProcess && actualNumberProcess > 0) //se ainda tive processor no vetor
			{
				value = 0;
			}
			else
			{
				value = i;
			}
			for(int p = value; p < ableQueue; p++)
			{
				if(processObject[p].creationTime <= cicleTime) // P significa indice de posi��o (posiiton)
				{
					cout << ", " << processObject[p].name;
				}
			}

		}



		else if(processObject[i].processTime <= quantum && processObject[i].processTime > 0)
		{
			cout << "\n\nCiclo " << cicleTime << " -- \n";



			processObject[i].processTime = 0;

			processObject[i].turnAround = cicleTime - processObject[i].creationTime;

			averageTournaround += cicleTime - processObject[i].creationTime;



			cout << "Executando: " << processObject[i].name;
			cout << "\nFila de Aptos";
			ableQueue = (numberOfProcess - i);
			if((i + 1) >= numberOfProcess && actualNumberProcess > 0) //se ainda tive processor no vetor
			{
				value = 0;
			}
			else
			{
				value = (i+1);
			}
			for(int p = value; p < ableQueue; p++) // P significa position
			{
				if(processObject[p].creationTime <= cicleTime)
				{
					cout << ", " << processObject[p].name << endl;
				}

			}
			cicleTime += processObject[i].processTime;
			cout<<"\nTempo:" << cicleTime;
			cout << "\nProcesso " << processObject[i].name << " finalizado!" << endl << " Turnaround: " << processObject[i].turnAround << endl;
			cout << endl;

			processControl--;

			//Apagar essas função do vetor
			//TempoProcesso.erase(TempoProcesso.begin() + i);
			//tempoCriacao.erase(tempoCriacao.begin() + i);
			//TempoChegada.erase(TempoChegada.begin() + i);
			//nomeProcesso.erase(nomeProcesso.begin() + i);
			//InicioES.erase(InicioES.begin() + i);
			actualNumberProcess--;
			activate = true;

		}

		i++;


		if(processObject[i].creationTime > cicleTime)
		{
			i = 0; //zerar
		}


		if(i == numberOfProcess)
		{
			i = 0;
		}

	}

	return 0;


}
