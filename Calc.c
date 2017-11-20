#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.1415926

double s(double),c(double),t(double);

int main(void){

    double a,ang,fa,x,y;
    char cdc,sw,fun;
    int cd=0;

    printf("===================================================\n");
    printf("|        Calculator  17C1001 Tomohiro Aoki        |\n");
    printf("|-------------------------------------------------|\n");
    printf("|      Arithmetic mode:[a] Function mode:[f]      |\n");
    printf("|  sin(x),cos(x),tan(x):[sx],[cx],[tx] x(degree)  |\n");
    printf("|                    Quit:[q]                     |\n");   
    printf("===================================================\n\n");

    printf("First, input a(arithmetic mode) or f(function mode)\n");

    while(1){ //first mode select
        scanf("%c",&cdc);
        if(cdc=='a'){
            cd = 0;
            break;
        }else if(cdc=='f'){
            cd = 1;
            break;
        }else if(cdc=='q'){
            exit(1);
        }
    }

    if(cd == 0){ //first input
        scanf("%lf",&a);
    }else if(cd == 1){
        scanf("%c",&fun);
        while(fun == '\n'){
            scanf("%c",&fun);
        }
        if(fun=='q'){
            exit(1);
        }else{
            scanf("%lf",&ang);
            switch(fun){
                case's':
                    a=s(ang);
                    break;
                case'c':
                    a=c(ang);
                    break;
                case't':
                    a=t(ang); 
                    break; 
                default:
                    break;
            }
        }
    }
    while(1){
        if(cd == 0){ //arithmetic mode
            while(cd == 0){
                scanf("%c",&sw);
                while(sw == '\n'){
                    scanf("%c",&sw);
                }
                if(sw == 'f'){ 
                    cd = 1;
                    break;
                }else if(sw == 'q'){
                    exit(1);                
                }else{
                    scanf("%lf",&x);
                    while(x == '\n'){
                        scanf("%lf",&x);
                    }
                        switch(sw){
                            case'+':
                                a+=x;
                                printf("=%lf\n",a);
                                break;
                            case'-':
                                a-=x;
                                 printf("=%lf\n",a);
                                break;
                            case'*':
                                a*=x;
                                printf("=%lf\n",a);
                                break;
                            case'/':
                                if(x==0){
                                    printf("You can't divid by 0\n");
                                    break;
                                }else{
                                    a/=x;
                                    printf("=%lf\n",a);
                                    break;    
                                }
                            default:
                                break;
                        }
                }
                
            }
        }else if(cd==1){ //function mode
            scanf("%c",&sw);
            while(sw == '\n'){
                scanf("%c",&sw);
            }
            if(sw == 'a'){
                cd = 0;
            }else if(sw == 'q'){
                exit(1);     
            }else{
                scanf("%c",&fun);
                scanf("%lf",&ang);
                    switch(fun){
                        case's':
                            x=s(ang);
                            break;
                        case'c':
                            x=c(ang);
                            break;
                        case't':
                            x=t(ang); 
                            break;
                        case'q':
                            cd=1;
                            break; 
                        default:
                            break;
                    }
                    switch(sw){
                        case'+':
                            a+=x;
                            printf("=%lf\n",a);
                            break;
                        case'-':
                            a-=x;
                            printf("=%lf\n",a);
                            break;
                        case'*':
                            a*=x;
                            printf("=%lf\n",a);
                            break;
                        case'/':
                            if(x==0){
                                printf("You can't divid by 0\n");
                                break;
                            }else{
                                a/=x;
                                printf("=%lf\n",a);
                            break;    
                            }
                        case'q':
                            cd=2;
                            break;
                        default:
                            break;
                    }
            }
                
                     
        }        
    }    
        
    return 0;

}
     
double s(double angle){
	double rst;
	rst = sin(angle*PI/180.0);
	return rst;
}

double c(double angle){
	double rst;
	rst = cos(angle*PI/180.0);
	return rst;
}

double t(double angle){
	double rst;
	rst = tan(angle*PI/180.0);
	return rst;
}

//計算の部分は数値関数同じものを使うので違うものだけをif文に入れるとよりシンプルにできる。