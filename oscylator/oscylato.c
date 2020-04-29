//zadanie oscylator harmoniczny
#include <stdio.h>
#include <math.h>


float r[2] = {0.5, 0.75};
float v[2] = {0, 0};
float k = 2;
const float m = 0.5;
const float dt = 0.02;

void euler(){
    float fx = -k*r[0];
    float fy = -k*r[1];
    float F[2] = {fx, fy};

    float rOld[2] = {r[0], r[1]};
    float vOld[2] = {v[0], v[1]};
    float t0 = 0;
    const float tn = 5;
    FILE* wp = fopen("euler.txt", "w");
    int i = 0;
    fprintf(wp,"# \t\t\tt \t\t\tx \t\t\ty \t\t\tvx \t\t\tvy\t\tfx\t\tfy \t\t\tec\n");

    while (t0 <= tn)
    {
        F[0] = -k*r[0];
        F[1] = -k*r[1];
        r[0] += v[0] *dt;
        r[1] += v[1] * dt;
        v[0] += F[0]/m * dt; 
        v[1] += F[1]/m * dt;
        float v2 = v[0] * v[0] + v[1]*v[1];
        float r2 = r[0] * r[0] + r[1]*r[1];
        float ec = (m*v2)/2 + (k*r2)/2;
        t0 += dt;
        fprintf(wp ,"%d  %f  %e  %e  %e  %e  %e %e %e\n", i, t0, r[0], r[1], v[0], v[1], F[0], F[1], ec);
        i++;


    }

    fclose(wp);
}

void podstawowa_varleta(){
    float fx = -k*r[0];
    float fy = -k*r[1];
    float F[2] = {fx, fy};
    float t0 = 0;
    const float tn = 5;
    float rMinus[2];
    float rPlus[2];
    float ec;
    rPlus[0] = r[0]+v[0]*dt + F[0]/(2*m) * dt *dt;
    rPlus[1] = r[1]+v[1]*dt + F[1]/(2*m) * dt *dt;

    FILE* wp = fopen("pod_varlera.txt", "w");
    int i = 0;
    fprintf(wp,"# \t\t\tt \t\t\tx \t\t\ty \t\t\tvx \t\t\tvy\t\tfx\t\tfy \t\t\tec\n");
    while (t0 <= tn)
    {
        t0 += dt;
        F[0] = -k*r[0];
        F[1] = -k*r[1];
        rMinus[0] = r[0];
        rMinus[1] = r[1];
        r[0] = rPlus[0];
        r[1] = rPlus[1];

        rPlus[0] = -rMinus[0] + 2*r[0] + F[0]/m * powf(dt, 2);
        rPlus[1] = -rMinus[1] + 2*r[1] + F[1]/m * powf(dt, 2);
        v[0] = (rPlus[0] - rMinus[0])/(2*dt);
        v[1] = (rPlus[1] - rMinus[1])/(2*dt);
        float v2 = v[0] * v[0] + v[1]*v[1];
        float r2 = r[0] * r[0] + r[1]*r[1];
        ec = (m*v2)/2 + (k*r2)/2;
       

    }
    fclose(wp);
}

int metoda_predkosciowa(){
    float fx = -k*r[0];
    float fy = -k*r[1];
    float F[2] = {fx, fy};
    float FOld[2];
    float t0 = 0;
    float ec;
    const float tn = 5;
    int i = 0;

    FILE* wp = fopen("pred_varlera.txt", "w");
    int i = 0;
    fprintf(wp,"# \t\t\tt \t\t\tx \t\t\ty \t\t\tvx \t\t\tvy\t\tfx\t\tfy \t\t\tec\n");
   
    while (t0 < tn)
    {
        FOld[0] = F[0];
        FOld[1] = F[1];
        F[0] = -k*r[0];
        F[1] = -k*r[1];
        t0 += dt;
        r[0] += v[0] + FOld[0]/(2*m) * powf(dt, 2);
        r[1] += v[1] + FOld[1]/(2*m) * powf(dt, 2);
        v[0] += (F[0]+ FOld[0])/(2*m) * dt;
        v[0] += (F[0]+ FOld[0])/(2*m) * dt;
        v[1] += (F[1]+ FOld[1])/(2*m) * dt;
        float v2 = v[0] * v[0] + v[1]*v[1];
        float r2 = r[0] * r[0] + r[1]*r[1];
        ec = (m*v2)/2 + (k*r2)/2;
         fprintf(wp ,"%d  %f  %e  %e  %e  %e  %e %e %e\n", i, t0, r[0], r[1], v[0], v[1], F[0], F[1], ec);
        i++;
    }
    fclose(wp);
    
}

int main(int argc, char const *argv[])
{
    int dec;
    printf("1-metoda eulera 1 \n 2- zadanie 2 \n 3-zadanie 3\n");

    scanf("%d", &dec);
    if(dec==1){
        euler();
    }else if(dec == 2){
        podstawowa_varleta();
    }

    return 0;
}
