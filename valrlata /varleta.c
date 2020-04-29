

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
    float F[2] = {1, 4};
    float v[2] = {1, 4};
    float ec;
    int i = 0;
    float rMinus[2];
    float rPlus[2];
    FILE *fl = fopen("dataVq1.txt", "w");
    fprintf(fl, "#   t    x    y    vx    vy     ec\n");
    
    rPlus[0] = r[0] + v[0]*dt + F[0]/(2*m) *dt*dt;
    rPlus[1] = r[1] + v[1]*dt + F[1]/(2*m) *dt*dt;

    while (t0 <= tn)
    {
        
        t0 += dt;
        rMinus[0] = r[0];
        rMinus[1] = r[1];
        r[0] = rPlus[0];
        r[1] = rPlus[1];

        rPlus[0] = -rMinus[0] + 2*r[0] + F[0]/m * powf(dt, 2);
        rPlus[1] = -rMinus[1] + 2*r[1] + F[1]/m * powf(dt, 2);
        v[0] = (rPlus[0] - rMinus[0]) / (2*dt);
        v[1] = (rPlus[1] - rMinus[1]) / (2*dt);


        float ek = m/2*(powf(v[0], 2) + powf(v[1], 2));
        ep = m * r[1] * g;
        ec = ep + ek;
        fprintf(fl ,"%d  %f  %e  %e  %e  %e %e\n", i, t0, r[0], r[1], v[0], v[1], ec);

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
    float rMinus[2];
    float rPlus[2];
    float ep = m*g*r[1];
    
    FILE *fl = fopen("dataVq2.txt", "w");
    fprintf(fl, "#   t    x    y    vx    vy     ec\n");

    rPlus[0] = r[0] + v[0]*dt + F[0]/(2*m) *dt*dt;
    rPlus[1] = r[1] + v[1]*dt + F[1]/(2*m) *dt*dt;
    fprintf(fl ,"%d %f  %e  %e  %e  %e %s\n", 0, t0, r[0], r[1], v[0], v[1], " ");

    while (r[1] > 0)
    {
        rMinus[0] = r[0];
        rMinus[1] = r[1];
        r[0] = rPlus[0];
        r[1] = rPlus[1];

        rPlus[0] = -rMinus[0] + 2*r[0] + F[0]/m * powf(dt, 2);
        rPlus[1] = -rMinus[1] + 2*r[1] + F[1]/m * powf(dt, 2);
        v[0] = (rPlus[0] - rMinus[0]) / (2*dt);
        v[1] = (rPlus[1] - rMinus[1]) / (2*dt);

        float ek = m/2*(powf(v[0], 2) + powf(v[1], 2));
        ep = m*g*r[1];
        ec = ep + ek;
        t0 += dt;
        fprintf(fl ," %i %f  %e  %e  %e  %e %e\n", i ,t0, r[0], r[1], v[0], v[1], ec);
        i++;

    }
    fclose(fl);
}

void q3(){

    float r[2] = {0, 0};
    float F[2] = {0, -m*g};
    float v[2] = {5, 4};
    float ec;
    int i = 1;
    float rMinus[2];
    float rPlus[2];
    float ep = m*g*r[1];
    
    FILE *fl = fopen("dataVq3.txt", "w");
    fprintf(fl, "#   t    x    y    vx    vy     ec\n");

    rPlus[0] = r[0] + v[0]*dt + F[0]/(2*m) *dt*dt;
    rPlus[1] = r[1] + v[1]*dt + F[1]/(2*m) *dt*dt;
    fprintf(fl ,"%d %f  %e  %e  %e  %e %s\n", 0, t0, r[0], r[1], v[0], v[1], " ");
    
    while (r[1] >= 0)
    {
        rMinus[0] = r[0];
        rMinus[1] = r[1];
        r[0] = rPlus[0];
        r[1] = rPlus[1];

        rPlus[0] = -rMinus[0] + 2*r[0] + F[0]/m * powf(dt, 2);
        rPlus[1] = -rMinus[1] + 2*r[1] + F[1]/m * powf(dt, 2);
        v[0] = (rPlus[0] - rMinus[0]) / (2*dt);
        v[1] = (rPlus[1] - rMinus[1]) / (2*dt);

        float ek = m/2*(powf(v[0], 2) + powf(v[1], 2));
        ep = m*g*r[1];
        ec = ep + ek;
        t0 += dt;
        fprintf(fl ,"%d %f  %e  %e  %e  %e %e\n", i, t0, r[0], r[1], v[0], v[1], ec);
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