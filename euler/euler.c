#include <stdio.h>
#include <math.h>

const float g = 9.81; // m/s^2
const float m = 5; // kg
const float dt = 0.02;
float t0 = 0;

void q1(){
    const float tn = 10;
    float ep = 0;

    float r[2] = {2, 3};
    float F[2] = {0, 0};
    float v[2] = {1, 4};
    float ec;
    int i = 0;
    FILE *fl = fopen("dataq1.txt", "w");
    fprintf(fl, "#   t    x    y    vx    vy     ec\n"); 
    while (t0 <= tn)
    {
        
        fprintf(fl ,"%d  %f  %e  %e  %e  %e %e\n", i, t0, r[0], r[1], v[0], v[1], ec);
        r[0] += v[0] * dt;
        r[1] += v[1] * dt;
        v[0] += F[0]/m * dt; 
        v[1] += F[1]/m * dt;
        float ek = m/2*(powf(v[0], 2) + powf(v[1], 2));
        ep = m*g*r[1];
        ec = ep + ek;
        fprintf(fl ,"%d  %f  %e  %e  %e  %e %e\n", i, t0, r[0], r[1], v[0], v[1], ec);
        t0 += dt;
        i++;

    }
    fclose(fl);
    
}

void q2(){

    float r[2] = {0, 10};
    float F[2] = {0, -m*g};
    float v[2] = {0, 0};
    float ec;
    int i = 0;
    float ep = m*g*r[1];
    
    FILE *fl = fopen("dataq2.txt", "w");
    fprintf(fl, "#   t    x    y    vx    vy     ec\n"); 
    while (r[1] > 0)
    {
        r[0] += v[0] * dt;
        r[1] += v[1] * dt;
        v[0] += F[0]/m * dt; 
        v[1] += F[1]/m * dt;
        float ek = m/2*(powf(v[0], 2) + powf(v[1], 2));
        ep = m*g*r[1];
        ec = ep + ek;
        t0 += dt;
        fprintf(fl ," %d %f  %e  %e  %e  %e %e\n", i ,t0, r[0], r[1], v[0], v[1], ec);
        i++;

    }
    fclose(fl);
}

void q3(){

    float r[2] = {0, 0};
    float F[2] = {0, -m*g};
    float v[2] = {5, 4};
    float ec;
    int i = 0;
    
    float ep = m*g*r[1];
    
    FILE *fl = fopen("dataq3.txt", "w");
    fprintf(fl, "#   t    x    y    vx    vy     ec\n");
    while (r[1] >= 0)
    {
        r[0] += v[0] * dt;
        r[1] += v[1] * dt;
        v[0] += F[0]/m * dt; 
        v[1] += F[1]/m * dt;
        float ek = m/2*(powf(v[0], 2) + powf(v[1], 2));
        ep = m*g*r[1];
        ec = ep + ek;
        fprintf(fl ,"%d %f  %e  %e  %e  %e %e\n", i, t0, r[0], r[1], v[0], v[1], ec);
        t0 += dt;
        i++;

    }
    fclose(fl);
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