#include<iostream>

using namespace std;
//mis vectores
int producto[3]={0,0,0};
int Cantidad[3];
int MI_FARMACIA();
float monedero();
float precio();
//mis funciones declaradas
int main()
{
	MI_FARMACIA();
}

int MI_FARMACIA()
{
	int i, Tproducto, r1, desicion_de_pago;
	float precio_a_pagar, precio_final_a_pagar, mon=300, acum;
	cout<<"Seleccione 3 de los siguientes productos"<<endl;
	cout<<"Seleccione los  productos"<<endl;
	for(i=0;i<3;i++)
	{
			do 
			{
				cout<<"(1) paracetamol (con oferta)"<<endl;
				cout<<"(2) desodorante (sin oferta)"<<endl;
				cout<<"(3) jarabe para la tos (con oferta)"<<endl;
				cout<<"(4) X-ray (sin oferta)"<<endl;
				do
				{
					cin>>Tproducto;
				}
				while(Tproducto!=1 && Tproducto!=2 && Tproducto!=3 && Tproducto!=4);
			}
			while((producto[0]==Tproducto)|| (producto[1]==Tproducto) || (producto[2]==Tproducto));
			producto[i]=Tproducto;
			cout<<"Ingrese la cantidad de su producto "<<i+1<<endl;
			cin>>Cantidad[i];
	}
	precio_a_pagar=precio();
	cout<<"cuenta con monedero electronico"<<endl;
	cout<<"(1) SI (2) NO"<<endl;
	do
	{
		cin>>r1;
	}
	while(r1!=1 && r1!=2);
	if(r1==1)
	{
		cout<<"El total de los productos es de: "<<precio_a_pagar<<endl;
		cout<<"El saldo en su monedero es de: "<<mon<<endl;
		if(mon>=precio_a_pagar)
		{
		    acum=monedero();
			mon=mon-precio_a_pagar+acum;
			cout<<"Su saldo es suficiente para pagar la cuenta"<<endl;
			cout<<"realizando compra espere porfavor......"<<endl;
			cout<<"su compra ha sido exitosa..."<<endl;
			cout<<"Su saldo actual en el monedero es de: "<<mon<<endl;
			cout<<"'VUELVA PRONTO'"<<endl;
		}
		else
		{
			cout<<"Los puntos no son suficientes para realizar su compra"<<endl;
			cout<<"Opcion (1) Si desea pagar en efectivo "<<endl;
			cout<<"Si desea realizar su pago con su monedero y el resto en efectivo"<<endl;
			cin>>desicion_de_pago;
			if(desicion_de_pago==1)
			{
				cout<<"El total es de: "<<precio_a_pagar<<endl;
				acum=monedero();
				mon=mon+acum;
				cout<<"Su saldo actual en el monedero es de: "<<mon<<endl;
			}
			else
			{
				mon=precio_a_pagar-mon;
				cout<<"Resta por pagar efectivo: "<<mon<<endl;
				acum=monedero();
				cout<<"Su saldo actual en el monedero es: "<<acum<<endl;
			}
		}
	}
	else
	{
		cout<<"El total de los productos es de: "<<precio_a_pagar<<endl;
	}	
}
//
float precio()
{
	int i;
	float acum=0;
	int paracetamol=45, desodorante=75, jarabe_para_la_tos=85, X_ray=129;
	for(i=0;i<3;i++)
	{
		switch(producto[i])
			{
				case 1:
					acum=acum+Cantidad[i]*paracetamol;
					break;
				case 2:
					acum=acum+Cantidad[i]*desodorante;
					break;
				case 3:
					acum=acum+Cantidad[i]*jarabe_para_la_tos;
					break;
				case 4:
					acum=acum+Cantidad[i]*X_ray;
					break;	
			}
	}
	return acum;
}
//
float monedero()
{
	int  i;
	float p ,p1 ,p3,porcentaje=0.10;
	float monedero_electronico=0;
	float mon_electronico;
	int paracetamol=45,jarabe_para_la_tos=85 ;
	for(i=0;i<3;i++)
	{
		switch(producto[i])
		{
			case 1:
				p=paracetamol*Cantidad[i];
				p1=p*porcentaje;
				break;
			case 3:
				p=jarabe_para_la_tos*Cantidad[i];
				p3=p*porcentaje;
				break;
		}
		mon_electronico=p1+p3;
	}
	
	return mon_electronico;
}
