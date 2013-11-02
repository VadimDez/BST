#include <QtCore/QCoreApplication>
#include <iostream>
#include <malloc.h>
using namespace std;
struct campi
{
    int codice;
    char descrizione [20];
};
struct dati
{
    int info;
    struct dati *dx, *sx;
};
struct nodo
{
    dati info;
    struct nodo *sx,*dx;
};
int vedi_dato(dati* d);
struct nodo *radice;
struct nodo *rad;
void inizializza ();
void operazione (char testata[]);
struct nodo* generanodo (int i);
struct nodo* trovanodo (dati dato, struct nodo *p);
int confrontadati (dati dato1, dati dato2);
int leggidati (dati *d);
void stampadato (dati d);
void stamparicorsiva (struct nodo *p);
void stamaalbero ();
void trovaMin(struct nodo* radice);
void trovaMax(struct nodo* radice);
void poststamparicorsiva (struct nodo *p);
void prestamparicorsiva (struct nodo *p);
void ricerca(int val, nodo *p);

// inizializza la radice a NULL
void inizializza ()
{
    radice = NULL;
    return;
}
struct nodo *generanodo (int i)
{
    struct nodo *p = NULL;
    dati d;
    int fine;
    fine = vedi_dato(&d);
    while(fine==0)
    {
        cout<<"inserisci il dato da inserire nel nodo"<<endl;
        cout<<"digita 0 per terminare l'esecuzione"<<endl;
        cin>>d.info;
        if(d.info!=0)
        {
            if(i==0)
            {
                p = trovanodo(d,p);
                rad=p;
            }
            else
            {
                p = trovanodo(d,p);
            }
        }
        if(d.info==0)
            fine=1;
    }
    return p;
}
struct nodo *trovanodo (dati dato, struct nodo *p)
{
    if (p==NULL)
    {
        p = new struct nodo;
        p->info=dato;
        p->sx=NULL;
        p->dx=NULL;
    }
    else
    {
        switch (confrontadati(dato, p->info))
        {
        case 1:
            p->sx=trovanodo(dato, p->sx);
            break;
        case 2:
            p->dx=trovanodo(dato, p->dx);
            break;
        case 3:
            cout<< "Dato già presente, non inserito."<<endl;
        }
    }
    return p;
}
int confrontadati(dati dato1, dati dato2)
{
    if(dato1.info<dato2.info)
    {
        return 1;
    }
    else if(dato1.info>dato2.info)
    {
        return 2;
    }
    else if(dato1.info==dato2.info)
    {
        return 3;
    }
}
void stampaalbero ()
{
    cout<< "Stampa ordinata:"<<endl;
    stamparicorsiva(rad);
}
//funzione per la stampa
void stamparicorsiva (struct nodo *p)
{
    if(p!=NULL)
    {
        stamparicorsiva(p->sx);
        leggidati(&p->info);
        stamparicorsiva(p->dx);
    }
    return;
}
//funzione per la stampa in preorder
void poststamparicorsiva (struct nodo *p)
{
    if(p!=NULL)
    {
        poststamparicorsiva(p->sx);
        poststamparicorsiva(p->dx);
        leggidati(&p->info);
    }
    return;
}
//funzione per la stampa in postorder
void prestamparicorsiva (struct nodo *p)
{
    if(p!=NULL)
    {
        leggidati(&p->info);
        prestamparicorsiva(p->sx);
        prestamparicorsiva(p->dx);
    }
    return;
}
void trovaMin(struct nodo* p)
{
    if(p==NULL)
        cout<<"albero vuoto o elemento non trovato"<<endl;
    else if(p->sx==NULL)
    {
        cout<<"il valore minimo e\'"<<endl;
        leggidati(&p->info);
    }
    else
        trovaMin(p->sx);
}
void trovaMax(struct nodo* p)
{
    if(p==NULL)
        cout<<"albero vuoto o elemento non trovato"<<endl;
    else if(p->dx==NULL)
    {
        cout<<"il valore massimo e\'"<<endl;
        leggidati(&p->info);
    }
    else
        trovaMax(p->dx);

}
int vedi_dato(dati* d)
{
    if (d==NULL)
        return 1;
    else
    {
        return 0;
    }
}

void ricerca(int val,nodo *p)
{
    if(p==NULL)
        cout<<"albero vuoto"<<endl;
    else if(val==leggidati(&p->info))
        cout<<"valore trovato"<<endl;
    else if(val<leggidati(&p->info))
        ricerca(val,radice->sx);
    else
        ricerca(val,radice->dx);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    dati radice;

    int scelta,i(0);
    bool exit=false;
    do
    {
        do
        {
            cout <<"Inserisci [1] per inserire dati " << endl;
            cout <<"Inserisci [2] per trovaare min"<<endl;
            cout <<"Inserisci [3] per trovaare max"<< endl;
            cout <<"Inserisci [4] per la ricerca"<<endl;
            cout <<"Inserisci [5] per la stampa inorder"<<endl;
            cout <<"Inserisci [6] per la stampa preorder"<<endl;
            cout <<"Inserisci [7] per la stampa postordere" << endl;
            cout <<"Inserisci [0] per uscire"<<endl;
            cin>>scelta;
        }while(scelta != 0 && (scelta < 1 && scelta > 7));
        switch(scelta)
        {
        case 1:
            inizializza();
            generanodo(i++);
            break;
        case 2:
            trovaMin(rad);
            break;
        case 3:
            trovaMax(rad);
            break;
        case 4:
            cout <<"Inserisci il numero da cerare: ";
            int num;
            cin >> num;
            ricerca(num,rad);
            break;
        case 5:
            stampaalbero();
            break;
        case 6:
            prestamparicorsiva(rad);
            break;
        case 7:
            poststamparicorsiva(rad);
            break;
        case 0:
            exit = true;
            break;
        }
    }while(!exit);
    return 0;
}
int leggidati (dati* d)
{
    if (d==NULL)
        return 1;
    else
    {
        cout<<d->info<<endl;
        return 0;
    }
}
