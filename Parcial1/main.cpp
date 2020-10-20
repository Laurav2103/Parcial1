#include <iostream>
#include <math.h>

using namespace std;

//Definicion de funciones
bool defensivo(float HD, float posy, float ang, float Vin,float d);

void puntos(float *, float *, float , float ,float );
void puntos2(float *,float *,float ,float );

int main()
{
    //DEFINICION CONDICIONES INICIALES:
    float d=1000,HD=200,H0=50;
    float angulo[3]={0.5,0.9,1.2};
    float v[3]={0,0,0};
    puntos(angulo,v,d,HD,H0);
    cout<<"d,HD y H0 se dan de la siguiente forma:"<<endl;
    cout<<"d(metros): "<<d<<'\n'<<"HD(metros): "<<HD<<'\n'<<"H0(metros): "<<H0<<'\n';
    cout<<"Los valores de velocidad y angulo para que ocurra el segundo caso son:"<<endl;
    for (int i=0;i<3;i++) cout<<"Vin: "<<v[i]<<" m/s "<<" Angulo: "<<angulo[i]<<" rad"<<endl;
    puntos2(angulo,v,d,H0);
    cout<<"Los valores de velocidad y angulo para que ocurra el segundo caso son:"<<endl;
    for (int i=0;i<3;i++) cout<<"Vin: "<<v[i]<<" m/s "<<" Angulo: "<<angulo[i]<<" rad"<<endl;


return 0;
}
bool defensivo(float HD, float posy, float ang, float Vin,float d ){ //determina si se dispara o no el canon defensivo
    float tsuelo= (Vin*sin(ang)+sqrt(Vin*Vin*sin(ang)*sin(ang)+2*9.81*posy))/9.81;  // tiempo que se demora en llegar al suelo la bala ofensiva
    float tsim=0,x,y;
    bool efectivo=false;
    for(int i=0;i<=1000;i++){
        tsim=tsuelo*i/1000; // genera los diferetnes tiempos para generar la parabola de tiro
        x=Vin*cos(ang)*tsim;
        y=posy+Vin*sin(ang)*tsim-4.9*tsim*tsim;
        if (sqrt(pow((d-x),2)+pow((HD-y),2))<=0.05*d){//si esta dentro del rango de la circunferencia
            efectivo=true;
            break;
        }

    }
    return efectivo;
}
void puntos(float *angulo,float *v,float d,float HD,float H0){
    double xy[3][2]={{d,HD},{(d-0.025*d),HD},{(d+0.025*d),(HD+0.025*d)}};
    for(int i=0;i<3;i++){
        v[i]=(xy[i][0]/cos(angulo[i]))*sqrt(4.9/(xy[i][0]*tan(angulo[i])+H0-xy[i][1]));// velocidad que compromete el canon defensivo
    }

}
//Para el segundo caso:
void puntos2(float *angulo,float *v,float d,float H0){
    double xy[3][2]={{0,H0},{(0.005*d),H0},{(0.025*d),(H0+0.025*d)}};
    for(int i=0;i<3;i++){
        v[i]=(xy[i][0]/cos(angulo[i]))*sqrt(4.9/(xy[i][0]*tan(angulo[i])+H0-xy[i][1]));// velocidad que compromete el canon defensivo
    }

}

//





