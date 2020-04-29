// implementacja prędkościowej metody Varleta do równań Netwona

#include <stdio.h>
#include <math.h>

const float m = 5;
const float g = 9.81;
const float dt = 0.02;

float t0 = 0;

void q1(){
    float tN = 10;
    float ep = 0;
    float ec;

    float r[2] = {2, 3};
    float v[2] = {1, 4};
    float F[2] = {0, 0};
    FILE* file = fopen("VTNz1.txt", "w");
    int i=0;
    fprintf(file,"# \t\t\tt \t\t\tx \t\t\ty \t\t\tvx \t\t\tvy \t\t\tec\n");
    while (t0 <= tN)
    {
        t0 += dt;
        r[0] += v[0]*dt + F[0]/(2*m) * dt * dt;
        r[1] += v[1]*dt + F[1]/(2*m) * dt * dt;
        v[0] += (F[0] + F[0])/(2*m) * dt;
        v[1] += (F[1] + F[1])/(2*m) * dt;
        float ek = m/2*(powf(v[0], 2) + powf(v[1], 2));
        ep = m*g*r[1];
        ec = ep + ek;

        fprintf(file ,"%d  %e  %e  %e  %e  %e %e\n", i, t0, r[0], r[1], v[0], v[1], ec);
        i++;
    }
    

    fclose(file);

}

void q2(){
    float tN = 10;

    float r[2] = {0, 10};
    float v[2] = {0, 0};
    float F[2] = {0, -m*g};
    float ep = m*g*r[1];
    float ec;

    FILE* file = fopen("VTNz2.txt", "w");
    int i=0;
    fprintf(file,"# \t\t\tt \t\t\tx \t\t\ty \t\t\tvx \t\t\tvy \t\t\tec\n");

    while (r[1] > 0)
    {
        t0 += dt;
        r[0] += v[0]*dt + F[0]/(2*m) * dt * dt;
        r[1] += v[1]*dt + F[1]/(2*m) * dt * dt;
        v[0] += (F[0] + F[0])/(2*m) * dt;
        v[1] += (F[1] + F[1])/(2*m) * dt;
        float ek = m/2*(powf(v[0], 2) + powf(v[1], 2));
        ep = m*g*r[1];
        ec = ep + ek;

        fprintf(file ,"%d  %f  %e  %e  %e  %e %e\n", i, t0, r[0], r[1], v[0], v[1], ec);
        i++;
    }
    

    fclose(file);

}

void q3(){
    float tN = 10;
    float ep;
    float ec;

    float r[2] = {0, 0};
    float v[2] = {5, 4};
    float F[2] = {0, -m*g};
    FILE* file = fopen("VTNz3.txt", "w");
    ep = m*g*r[1];
    int i=0;
    fprintf(file,"# \t\t\tt \t\t\tx \t\t\ty \t\t\tvx \t\t\tvy \t\t\tec\n");

    while (r[1]>= 0)
    {
        t0 += dt;
        r[0] += v[0]*dt + F[0]/(2*m) * dt * dt;
        r[1] += v[1]*dt + F[1]/(2*m) * dt * dt;
        v[0] += (F[0] + F[0])/(2*m) * dt;
        v[1] += (F[1] + F[1])/(2*m) * dt;
        float ek = m/2*(powf(v[0], 2) + powf(v[1], 2));
        ep = m*g*r[1];
        ec = ep + ek;

        fprintf(file ,"%d  %f  %e  %e  %e  %e %e\n", i, t0, r[0], r[1], v[0], v[1], ec);
        i++;
    }
    

    fclose(file);

}



int main(int argc, char const *argv[])
{
    int dec;
    printf("1-zadanie 1 \n 2- zadanie 2 \n 3-zadanie 3\n");

    scanf("%d", &dec);

    if(dec == 1){
        q1();

    }
    if(dec == 2){
        q2();
    }
    if(dec == 3){
        q3();
    }

    return 0;
}
