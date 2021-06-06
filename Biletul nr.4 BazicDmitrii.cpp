#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<cmath>
#include<conio.h>

using namespace std;

struct benef

{

char beneficiar[255];
char DenLoc[255]; //fix
char AdresaLoc[255];
char TipLoc[255];
int codLoc;
float media; //aria locuintei
int NRbenef;

struct note

   {

   int nota;
   struct dis

  { 
  int disciplina;
  }
  DIS;

}NOTA[50];

};

  int N=0;

  void save(benef *S)
{
	
	FILE *f;
	
	f=fopen("Benefic.txt","w+b");
	fprintf(f," %d\n",N);
	
	for(int i=0;i<N;i++)
	{
		fprintf(f,"%s %s %d %f %d\n",S[i].beneficiar,S[i].AdresaLoc,S[i].codLoc,S[i].media,S[i].NRbenef);
		
		for(int j=0;j<S[i].NRbenef;j++)
		{
				fprintf(f," %d\n",S[i].NOTA[j].nota);
		}
	}
		fprintf(stdout,"\n\n\tInformatia sa salvat cu succes\n");
	fclose(f);
}

void load(benef *S)
{
	FILE *f;   f=fopen("Benefic192.txt","r");
	fscanf(f,"%d",&N);
	
	for(int i=0;i<N;i++)
	{
		fscanf(f,"%s %s %d %f %d",&S[i].beneficiar,&S[i].AdresaLoc,&S[i].codLoc,&S[i].media,&S[i].NRbenef);
		
		for(int j=0;j<S[i].NRbenef;j++)
		{
				fscanf(f," %d",&S[i].NOTA[j].nota);
		}
	}
	fprintf(stdout,"\n\n\tInformatia s a extras cu succes\n");
	fclose(f);
}

int insertINT(char mess[]){int x;cout<<mess;cin>>x;return x;}

void insertBENEF(benef *S)

{

int i=N;

do

{

system("cls");

cout<<"["<<i+1<<"] Enter beneficiar="; cin>>S[i].beneficiar;
cout<<"["<<i+1<<"] Enter AdresaLoc="; cin>>S[i].AdresaLoc;
cout<<"["<<i+1<<"] Enter TipulLoc="; cin>>S[i].TipLoc;
cout<<"["<<i+1<<"] Enter codLoc="; cin>>S[i].codLoc;
cout<<"["<<i+1<<"] Enter DenLoc="; cin>>S[i].DenLoc;


S[i].media=0;

int j=0;

do{

cout<<"benefentul ["<<i+1<<"] aria["<<j+1<<"]=";

cin>>S[i].NOTA[j].nota ;
S[i].media+=S[i].NOTA[j].nota;

j++;

cout<<"\n note Press ESC for exit or any key ......"<<endl;
}while(_getch()!=27);

S[i].NRbenef=j;

S[i].media = S[i].media/S[i].NRbenef;

i++;

cout<<"\n beneficiar Press ESC for exit or any key ......"<<endl;

}while(_getch()!=27);
 N=i;
}

void showBENEF(benef *S)
{

system("cls");
int sp=2;

int k1=0, k2=sp, pagina=0;
if( N>0)

{

while(1)
 {

system("cls");

cout<<"-------------------------------------------------------------------------"<<endl;
cout<<setw(10)<<"Nr."<<setw(10)<<"beneficiar"<<setw(10)<<"AdresaLoc"<<setw(10)<<"codLoc"<<setw(10)<<"MEDIA"<<setw(10)<<"TipLoc"<<setw(10)<<"DenLoc"<<endl;

    for(int i=k1; i<k2;i++)
{

cout<<"-------------------------------------------------------------------------"<<endl;
cout<<setw(10)<<i+1<<setw(10)<<S[i].beneficiar<<setw(10)<<S[i].AdresaLoc<<setw(10)<<S[i].codLoc<<setw(10)<<S[i].media<<setw(10)<<S[i].TipLoc<<setw(10)<<S[i].DenLoc<<endl;

}cout<<"-- pagina "<<ceil((double)k1/sp)+1<<" din "<<ceil((double)N/sp)<<"-------------------------------------------------"<<endl;

int KEY= _getch();

/* + */ if(KEY == 43){ k1+=sp; k2+=sp; if(k2 > N){ k1=N-sp; k2=N; } }
/* - */ else if(KEY == 45){ k1-=sp; k2-=sp; if(k1 < 0){ k1=0; k2=sp; } }
/*ESC*/ else if(KEY == 27){ break; }

}

}else { cout<<" Nu sunt date pentru a afisa informatia "<<endl; }

}

void sumbenef(benef *S)

{

double s=0;
for(int i=0; i<N;i++)

{
s+=S[i].media;
}

cout<<" Suma mediilor = "<<s<<endl;

}

int meniu()

{

int key;

system("cls");

cout<<" \n\n\n\t\t MENIU"<<endl;
cout<<" \t\t 1. Insert beneficiar"<<endl;
cout<<" \t\t 2. Arata beneficiari"<<endl;
cout<<" \t\t 3. Suma beneficiari"<<endl;
cout<<" \t\t 4. Max Min beneficiari"<<endl;
cout<<" \t\t 5. Cautare beneficiari dupa AdresaLoc"<<endl;
cout<<" \t\t 6. Editare beneficiar dupa ID"<<endl;
cout<<" \t\t 7. Salveaza beneficiar"<<endl;
cout<<" \t\t 8. Incarca beneficiar din file"<<endl;
cout<<" \t\tESC. Exit"<<endl;

key=_getch();

return key;

}

int meniuCAUTA()

{

int key;

system("cls");

cout<<" \n\n\n\t\t MENIU CAUTARE "<<endl;
cout<<" \t\t 1. Cautare dupa beneficiar"<<endl;
cout<<" \t\t 2. Cautare dupa AdresaLoc"<<endl;
cout<<" \t\t 2. Cautare dupa TipLoc"<<endl;
cout<<" \t\t 3. Cautare dupa medie"<<endl;
cout<<" \t\t ESC. Exit"<<endl;

key=_getch();

return key;

}

void cautaBENEFICIAR(benef *S)
{

system("cls");

char beneficiarCAUTA[255];

cout<<" Enter beneficiar :";

cin>>beneficiarCAUTA;

cout<<"Cutarea dupa BENEFICIAR --------------------------------------------------------------"<<endl;
cout<<setw(10)<<"Nr."<<setw(10)<<"beneficiar"<<setw(10)<<"AdresaLoc"<<setw(10)<<"codLoc"<<setw(10)<<"MEDIA"<<setw(10)<<"AdresaLoc"<<setw(10)<<"DenLoc"<<endl;
for(int i=0; i<N;i++)

{

if( strcmp( S[i].beneficiar ,beneficiarCAUTA) == 0 )

{
cout<<"-------------------------------------------------------------------------"<<endl;
cout<<setw(10)<<i+1<<setw(10)<<S[i].beneficiar<<setw(10)<<S[i].AdresaLoc<<setw(10)<<S[i].codLoc<<setw(10)<<S[i].media<<setw(10)<<S[i].AdresaLoc<<setw(10)<<S[i].DenLoc<<endl;

}

}

system("pause");

}

void cautaAdresaLoc(benef *S)

{

system("cls");

char beneficiarCAUTA[255];

cout<<" Enter AdresaLoc :";

cin>>beneficiarCAUTA;

cout<<"Cutarea dupa AdresaLoc --------------------------------------------------------------"<<endl;
cout<<setw(10)<<"Nr."<<setw(10)<<"BENEFICIAR"<<setw(10)<<"AdresaLoc"<<setw(10)<<"codLoc"<<setw(10)<<"MEDIA"<<setw(10)<<"AdresaLoc"<<setw(10)<<"DenLoc"<<endl;

for(int i=0; i<N;i++)

{

if( strcmp( S[i].beneficiar ,beneficiarCAUTA) == 0 )

{

cout<<"-------------------------------------------------------------------------"<<endl;

cout<<setw(10)<<i+1<<setw(10)<<S[i].beneficiar<<setw(10)<<S[i].AdresaLoc<<setw(10)<<S[i].codLoc<<setw(10)<<S[i].media<<S[i].TipLoc<<setw(10)<<S[i].DenLoc<<setw(10)<<endl;

}} system("pause");

}

void cautaMEDIE(benef *S)

{

system("cls"); double MED; cout<<" Enter media :"; cin>>MED;

cout<<"Cutarea dupa AdresaLoc --------------------------------------------------------------"<<endl;
cout<<setw(10)<<"Nr."<<setw(10)<<"BENEFICIAR"<<setw(10)<<"AdresaLoc"<<setw(10)<<"codLoc"<<setw(10)<<"MEDIA"<<setw(10)<<"TIP LOC"<<setw(10)<<"DenLoc"<<endl;

for(int i=0; i<N;i++)

{

if( S[i].media == MED )

{

cout<<"-------------------------------------------------------------------------"<<endl;

cout<<setw(10)<<i+1<<setw(10)<<S[i].beneficiar<<setw(10)<<S[i].AdresaLoc<<setw(10)<<S[i].codLoc<<setw(10)<<S[i].media<<setw(10)<<S[i].TipLoc<<setw(10)<<S[i].DenLoc<<endl;

}

}

system("pause");

}

void cauta(benef *S)

{

bool xxx=false;

while(1){

system("cls");

switch(meniuCAUTA())

{

case 49: cautaBENEFICIAR(S); break;
case 50: cautaAdresaLoc(S); break;
case 51: cautaMEDIE(S); break;
case 27: xxx=true;

}

if(xxx) break;

}

}

void show_max_min_BENEF(benef *S)

{

int max,max_i;
max=S[0].media;

int min,min_i;
min=S[0].media;

for(int i=1; i<N;i++)

{

if(S[i].media>max)

{

max=S[i].media;

max_i=i;

}

if(S[i].media<min)

{

min=S[i].media;

min_i=i;

}

}

system("cls");

cout<<"-------------------------------------------------------------------------"<<endl;

cout<<setw(10)<<"beneficiar"<<setw(10)<<"AdresaLoc"<<setw(10)<<"codLoc"<<setw(10)<<"MEDIA"<<setw(10)<<"TIP LOC"<<endl;

cout<<"-------------------------------------------------------------------------"<<endl;

cout<<setw(10)<<S[max_i].beneficiar<<setw(10)<<S[max_i].AdresaLoc<<setw(10)<<S[max_i].codLoc<<setw(10)<<S[max_i].media<<endl;

cout<<"-------------------------------------------------------------------------"<<endl;

cout<<setw(10)<<S[min_i].beneficiar<<setw(10)<<S[min_i].AdresaLoc<<setw(10)<<S[min_i].codLoc<<setw(10)<<S[min_i].media<<endl;

cout<<"-------------------------------------------------------------------------"<<endl;

}

void edit(benef *S)

{

system("cls");

int ID; bool xxx = false;

do

{

cout<<" Enter benef ID=";

cin>>ID;

if( ID > 0 && ID <= N ){ ID--; xxx=true; }

else { cout<<" ID inexistent "<<endl; }

}while(xxx);

cout<<" Doriti sa modificati NUMELE BENEFICIRUL ? yes/no"<<endl;
if( _getch() == 'y' || _getch() == 'Y' ) { cout<<"beneficiar["<<ID+1<<"] beneficiarLE="<<S[ID].beneficiar<<" in Enter beneficiar=";cin>>S[ID].beneficiar; }

cout<<" Doriti sa modificati AdresaLoc ? yes/no"<<endl;
if( _getch() == 'y' || _getch() == 'Y' ) { cout<<"benefent ["<<ID+1<<"] AdresaLoc="<<S[ID].AdresaLoc<<" in Enter beneficiar=";cin>>S[ID].AdresaLoc; }

cout<<" Doriti sa modificati codLoc ? yes/no"<<endl;
if( _getch() == 'y' || _getch() == 'Y' ) { cout<<"Beneficiar ["<<ID+1<<"] codLoc="<<S[ID].codLoc<<" in Enter beneficiar=";cin>>S[ID].codLoc ; }

}

int main()

{

benef *p = new benef[100];

while(1)

{

switch(meniu())

{

case 49:system("cls"); insertBENEF(p); system("pause"); break;

case 50:system("cls"); showBENEF(p); system("pause"); break;

//case 51:system("cls"); NRbenef(p); system("pause"); break;
case 52:system("cls"); show_max_min_BENEF(p); system("pause"); break;
case 53:system("cls"); cauta(p); system("pause"); break;
case 54:system("cls"); edit(p); system("pause"); break;
case 55:system("cls"); save(p); system("pause"); break;
case 56:system("cls"); load(p); system("pause"); break;



case 27: exit(0);

}

}

return 0;

}

