#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAXCAR 20
#define MAXBIKE 50


typedef struct node
{
    int carSlot;
    struct node *carlink;
    int carHours;
    char carinfo[20];
    char carEntrytime[9];
    char carExittime[9];

    int BikeSlot;
    struct node *Bikelink;
    int BikeHours;
    char Bikeinfo[20];
    char BikeEntrytime[9];
    char BikeExittime[9];

}NODE;

//head pointers

NODE *startcar=NULL;  
NODE *startBike=NULL;  

//function declarations

void addCar();
int removeCar();
void searchCar();
void carCost();

void addBike();
int removeBike();
void searchBike();
void BikeCost();

int isvalidPlateNum(char* plateNumber);

int isCarPlateRepeated(char *plateNumber);
int isBikePlateRepeated(char *plateNumber);

 //initializations

int carcost=0, Bikecost=0;
    
int tlcar=0, tlBike=0;
    
int main()
{
  printf("\n\n\n\n\n\t\t\t\t\t\t\tVEHICLE PARKING SYSTEM\n\n\n");
  printf("\t\t\t-----------------------------------------------------------------------------------");
    
int choice1,choice2,data;    
printf("\n\n\n\n\n\t\t\t\t\t\t\tChoose the vehicle type: \n");
printf("\n\n\n\t\t\t\t\t\t\t1.Car\n\n\t\t\t\t\t\t\t2.Bike\n\n\t\t\t\t\t\t\t3.Quit\n\n\n");
printf("\t\t\t\t\t\t\t");
scanf("%d",&choice1);
system("cls");
do{
    
    switch(choice1)
    {
        case 1: printf("\n\n\n\n\n\n\t\t\t\t\t\t\twhat's the situation?\n\n\n");
                printf("\t\t\t-----------------------------------------------------------------------------------");
                printf("\n\n\n\t\t\t\t\t\t\t1.Add car\n\n\t\t\t\t\t\t\t2.Remove car\n\n\t\t\t\t\t\t\t3.Search car\n\n\t\t\t\t\t\t\t4.car revenue\n\n\t\t\t\t\t\t\t5.Back\n\n\t\t\t\t\t\t\t");
                scanf("%d",&choice2);
                system("cls");
                
                do{
                    switch(choice2)
                        {
                            case 1:addCar();
                                   break;
                            case 2:data=removeCar();
                                    if(data==1)
                                    {
                                        printf("\n\n\n\n\n\t\t\t\t\t\tNO CARS ARE PARKED IN THE LOT!!!\n\n");
                                        printf("\t\t\t\t\t\tpress ENTER to continue");
                                        getchar();getchar();
                                        system("cls");
                                    }
                                    if(data==2)
                                    {
                                        printf("\n\n\n\n\n\t\t\t\t\t\tcar is not present in the lot\n\n");
                                        printf("\t\t\t\t\t\tpress ENTER to continue");
                                        getchar();getchar();
                                        system("cls");
                                    }
                                    break;
                            case 3:searchCar();

                                    break;
                            case 4:carCost();
                                    break;                     
                        }
                        if(choice2!=5)
                        {
                            printf("\n\n\n\n\n\n\t\t\t\t\t\t\twhat's the situation?\n\n\n");
                            printf("\t\t\t-----------------------------------------------------------------------------------");
                            printf("\n\n\n\t\t\t\t\t\t\t1.Add car\n\n\t\t\t\t\t\t\t2.Remove car\n\n\t\t\t\t\t\t\t3.Search car\n\n\t\t\t\t\t\t\t4.car revenue\n\n\t\t\t\t\t\t\t5.Back\n\n\t\t\t\t\t\t\t");
                            scanf("%d",&choice2);
                            system("cls");
                        }
                        
                      }while(choice2<5);
                      system("cls");

                      break;


//Bike

        case 2: printf("\n\n\n\n\n\n\t\t\t\t\t\t\twhat's the situation?\n\n\n");
                printf("\t\t\t-----------------------------------------------------------------------------------");
                printf("\n\n\n\t\t\t\t\t\t\t1.Add Bike\n\n\t\t\t\t\t\t\t2.Remove Bike\n\n\t\t\t\t\t\t\t3.Search Bike\n\n\t\t\t\t\t\t\t4.Bike revenue\n\n\t\t\t\t\t\t\t5.Back\n\n\t\t\t\t\t\t\t");
                scanf("%d",&choice2);
                system("cls");
                
                do{
                    switch(choice2)
                        {
                            case 1:addBike();
                                   break;
                            case 2:data=removeBike();
                                    if(data==1)
                                    {
                                        printf("\n\n\n\n\n\t\t\t\t\t\tNo Bikes are present in the lot currently\n\n");
                                        printf("\t\t\t\t\t\tpress ENTER to continue");
                                        getchar();getchar();
                                        system("cls");
                                    }
                                    if(data==2)
                                    {
                                        printf("\n\n\n\n\n\t\t\t\t\tBike is not present in the lot\n\n");
                                        printf("\t\t\t\t\t\tpress ENTER to continue");
                                        getchar();getchar();
                                        system("cls");
                                    }
                                    break;
                            case 3:searchBike();

                                    break;
                            case 4:BikeCost();
                                    break;
                                
                            default : break;
                        
                        }
                        if(choice2!=5)
                        {
                            printf("\n\n\n\n\n\n\t\t\t\t\t\t\twhat's the situation?\n\n\n");
                            printf("\t\t\t-----------------------------------------------------------------------------------");
                            printf("\n\n\n\t\t\t\t\t\t\t1.Add Bike\n\n\t\t\t\t\t\t\t2.Remove Bike\n\n\t\t\t\t\t\t\t3.Search Bike\n\n\t\t\t\t\t\t\t4.Bike revenue\n\n\t\t\t\t\t\t\t5.Back\n\n\t\t\t\t\t\t\t");
                            scanf("%d",&choice2);
                            system("cls");  
                        }
                        
                      }while(choice2<5);
                      system("cls");  
                      break;

        case 5: exit(0);
                break;        


    }
    printf("\n\n\n\n\n\t\t\t\t\t\t\tChoose the vehicle type: \n");
    printf("\n\n\n\t\t\t\t\t\t\t1.Car\n\n\t\t\t\t\t\t\t2.Bike\n\n\t\t\t\t\t\t\t3.Quit\n\n\n");
    printf("\t\t\t\t\t\t\t");
    scanf("%d",&choice1);
    system("cls");
    
  }while(choice1<3);
  system("cls");


}

void addCar()
{
    
    if(MAXCAR>tlcar)  //checks if carlot already full
    {
        char cara[10];
        NODE *p=malloc(sizeof(NODE));
        printf("\n\n\n\n\n\t\t\t\t\t\tEnter your car plate number\n");
        printf("\n\t\t\t\t\t\t");
        //scanf("%s",p->carinfo);
        scanf("%s",cara);   
        if(isvalidPlateNum(cara)==0){
            printf("\n\n\t\t\t\t\t\tINVALID PLATE NUMBER!!!\n\n");
            printf("\t\t\t\t\t\tplease re-enter a valid plate number\n\n");
            printf("\t\t\t\t\t\tpress ENTER to continue");
            getchar();getchar();
            system("cls");
        }
        else if (isCarPlateRepeated(cara))
        {
            printf("\n\n\t\t\t\t\t\tCar with plate number %s is already parked.\n", cara);
            printf("\t\t\t\t\t\tPlease enter a different plate number.\n\n");
            printf("\t\t\t\t\t\tpress ENTER to continue");
            getchar();
            getchar();
            system("cls");
        }
        else
        {
            strcpy(p->carinfo,cara);
            p->carlink=NULL;
            
            int carTime;
            printf("\n\n\n\t\t\t\t\t\tNumber of hours you would like to park?");
            printf("\n\t\t\t\t\t\tRs 100/hr");
            printf("\n\n\t\t\t\t\t\t");
            scanf("%d",&carTime);
            p->carHours=carTime;
            carcost+=p->carHours*100;
            
            time_t tcar1 = time(NULL);
            struct tm *current_time = localtime(&tcar1);
            char current_time_str[9];  // HH:MM:SS format
            strftime(current_time_str, sizeof(current_time_str), "%H:%M:%S", current_time);
            strcpy(p->carEntrytime,current_time_str);
            printf("\n\n\t\t\t\t\t\tEntry time: %s\n", current_time_str);
            
            
            if (startcar==NULL)  //PARKING LOT IS EMPTY
            {
                startcar=p;
                tlcar++;
                //printf("%d\n",tlcar);
                
                printf("\n\t\t\t\t\t\tEntry Succesful\n");
                printf("\t\t\t\t\t\tpress ENTER to continue");
                getchar();
                getchar();
                system("cls");
                
            }
            else 
            {
                NODE *q=startcar;
                while(q->carlink!=NULL)
                {
                    q=q->carlink;
                }
                q->carlink=p;
                tlcar++;
                printf("\n\t\t\t\t\t\t\tEntry Succesfull\n\n");
                printf("\t\t\t\t\t\t\tpress ENTER to continue");
                getchar();
                getchar();
                system("cls");
            }

            p->carSlot=tlcar;
        }
    }
    else
    {
        printf("\n\t\t\t\t\t\tCar parking is Full\n\n");
        
        printf("\t\t\t\t\t\tpress ENTER to continue");
        getchar();
        getchar();
        system("cls");
    }
}

int removeCar()
{

    if(tlcar==0)
    {
        return 1;
    }
    else if(startcar!=NULL)
    {
        char carnum[20];  
        NODE *p=startcar;
        printf("\n\n\n\n\n\t\t\t\t\t\tEnter your car number \n");
        printf("\n\t\t\t\t\t\t");
        scanf("%s",carnum);

        char carplate[20];
        strcpy(carplate,p->carinfo);
        int carhours=p->carHours;
        
       if (strcmp(p->carinfo, carnum) == 0)
        {
            startcar = p->carlink;
            free(p);
            tlcar--;
        }
        else
        {
            NODE *q = NULL;
            while (p != NULL && strcmp(p->carinfo, carnum) != 0)
            {
                q = p;
                p = p->carlink;
            }

            if (p == NULL)
            {
                // Car not found
                return 2;
            }

            q->carlink = p->carlink;
            free(p);
            tlcar--;
        }
        
        
        
        time_t tcar2 = time(NULL);
        struct tm *current_time = localtime(&tcar2);
        char current_time_str[9];  // HH:MM:SS format
        strftime(current_time_str, sizeof(current_time_str), "%H:%M:%S", current_time);
        //strcpy(p->carExittime,current_time_str);
        printf("Exit time: %s\n", current_time_str);
        

        //BILL
        system("cls");
        printf("\n\n\n\n\n\t\t\t\t\t\t\t\tBILL FOR PARKING\n\n\n");
        printf("\t\t\t\t-----------------------------------------------------------------------------------\n\n");
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("\t\t\t\t\t\t\t%d-%02d-%02d\n\n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900);
        // printf("\t\t\t\t\t\t\tEntry time: %s\n\n", p->carEntrytime);
        // printf("\t\t\t\t\t\t\tExit time: %s\n\n", p->carExittime);
        printf("\t\t\t\t\t\t\tCar Number :\t%s\n\n",carplate);
        printf("\t\t\t\t\t\t\tPrice to Pay :\tRs %d\n",100*carhours);
        printf("\t\t\t\t-----------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t\t\tplease come again!!!\n\n\n");
        printf("\t\t\t\t\t\t\tpress ENTER to continue");
        getchar();getchar();
        system("cls");
    }
}

void carCost()
{
    printf("\n\n\n\n\n\t\t\t\t\t\tTotal money collected from car parking =  Rs %d \n\n",carcost);
    printf("\t\t\t\t\t\t\tpress ENTER to continue");
    getchar();getchar();
    system("cls");
}

void searchCar()
{
    char carnumb[20];
    int carcount=0;
    printf("\n\n\n\n\n\t\t\t\t\t\tcar plate number of the car to search: ");
    printf("\n\n\n\t\t\t\t\t\t");
    scanf("%s",carnumb);
    int carf=0;
    NODE* p=startcar;
    
    while(p!=NULL)
    {
        if(strstr(p->carinfo,carnumb)!=NULL)
        {
            printf("\t\t\t\t\t\t\tParking slot: %d\n\n",p->carSlot);
            printf("\t\t\t\t\t\t\tCar Plate number: %s\n\n",p->carinfo);
            printf("\t\t\t\t\t\t\tNo of hours for Parking:%d\n\n",p->carHours);
            printf("\t\t\t\t\t\t\tEntry time:%s\n\n",p->carEntrytime);
            printf("\n\n\n");
            carcount++;
        }

        p=p->carlink;
        carf=1;

    }
    
    if(carf==0)
    {
        printf("\n\n\n\t\t\t\t\t\tCAR NOT FOUND!!!\n\n");
    }

    printf("\t\t\t\t\t\tSearch results found for %s = %d\n\n",carnumb,carcount);
    printf("\t\t\t\t\t\tpress ENTER to continue");
    getchar();getchar();
    system("cls");
}


//Bike


void addBike()
{
    
    if(MAXBIKE>tlBike)
    {
        int isvalid;
        char Bikea[10];
        NODE *p=malloc(sizeof(NODE));
        printf("\n\n\n\n\n\t\t\t\t\t\tEnter your Bike plate number\n");
        printf("\n\t\t\t\t\t\t");
        //scanf("%s",p->Bikeinfo);
        scanf("%s",Bikea);
        isvalid=isvalidPlateNum(Bikea);
        if(isvalid==0){
            printf("\n\n\t\t\t\t\t\tINVALID PLATE NUMBER!!!\n\n");
            printf("\t\t\t\t\t\tplease re-enter a valid plate number\n\n");
            printf("\t\t\t\t\t\tpress ENTER to continue");
            getchar();getchar();
            system("cls");
        }
        else if (isBikePlateRepeated(Bikea))
        {
            printf("\n\n\t\t\t\t\t\tBike with plate number %s is already parked.\n", Bikea);
            printf("\t\t\t\t\t\tPlease enter a different plate number.\n\n");
            printf("\t\t\t\t\t\tpress ENTER to continue");
            getchar();
            getchar();
            system("cls");
        }
        else
        {
            strcpy(p->Bikeinfo,Bikea);
            p->Bikelink=NULL;
            
            int BikeTime;
            printf("\n\n\n\t\t\t\t\t\tNumber of hours you would like to park?");
            printf("\n\t\t\t\t\t\tRs 100/hr");
            printf("\n\n\t\t\t\t\t\t");
            scanf("%d",&BikeTime);
            p->BikeHours=BikeTime;
            Bikecost+=p->BikeHours*100;
            
            time_t tBike1 = time(NULL);
            struct tm *current_time = localtime(&tBike1);
            char current_time_str[9];  // HH:MM:SS format
            strftime(current_time_str, sizeof(current_time_str), "%H:%M:%S", current_time);
            strcpy(p->BikeEntrytime,current_time_str);
            printf("\n\n\t\t\t\t\t\tEntry time: %s\n", current_time_str);
            
            
            if (startBike==NULL)  //PARKING LOT IS EMPTY
            {
                startBike=p;
                tlBike++;
                //printf("%d\n",tlBike);
                
                printf("\n\t\t\t\t\t\tEntry Succesful\n");
                printf("\t\t\t\t\t\tpress ENTER to continue");
                getchar();
                getchar();
                system("cls");
                
            }
            else 
            {
                NODE *q=startBike;
                while(q->Bikelink!=NULL)
                {
                    q=q->Bikelink;
                }
                q->Bikelink=p;
                tlBike++;
                printf("\n\t\t\t\t\t\t\tEntry Succesfull\n\n");
                printf("\t\t\t\t\t\t\tpress ENTER to continue");
                getchar();
                getchar();
                system("cls");
            }

            p->BikeSlot=tlBike;
        }
    }
    else
    {
        printf("\n\t\t\t\t\t\tBike parking is Full\n\n");
        
        printf("\t\t\t\t\t\tpress ENTER to continue");
        getchar();
        getchar();
        system("cls");
    }
}


int removeBike()
{

    if(tlBike==0)
    {
        return 1;
    }
    else if(startBike!=NULL)
    {
        char Bikenum[20];  
        NODE *p=startBike;
        printf("\n\n\n\n\n\t\t\t\t\t\tEnter your Bike number \n");
        printf("\n\t\t\t\t\t\t");
        scanf("%s",Bikenum);

        char Bikeplate[20];
        strcpy(Bikeplate,p->Bikeinfo);
        int Bikehours=p->BikeHours;
        
       if (strcmp(p->Bikeinfo, Bikenum) == 0)
        {
            startBike = p->Bikelink;
            free(p);
            tlBike--;
        }
        else
        {
            NODE *q = NULL;
            while (p != NULL && strcmp(p->Bikeinfo, Bikenum) != 0)
            {
                q = p;
                p = p->Bikelink;
            }

            if (p == NULL)
            {
                // Bike not found
                return 2;
            }

            q->Bikelink = p->Bikelink;
            free(p);
            tlBike--;
        }
        
        
        
        time_t tBike2 = time(NULL);
        struct tm *current_time = localtime(&tBike2);
        char current_time_str[9];  // HH:MM:SS format
        strftime(current_time_str, sizeof(current_time_str), "%H:%M:%S", current_time);
        //strcpy(p->BikeExittime,current_time_str);
        printf("Exit time: %s\n", current_time_str);
        

        //BILL
        system("cls");
        printf("\n\n\n\n\n\t\t\t\t\t\t\t\tBILL FOR PARKING\n\n\n");
        printf("\t\t\t\t-----------------------------------------------------------------------------------\n\n");
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("\t\t\t\t\t\t\t%d-%02d-%02d\n\n",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900);
        // printf("\t\t\t\t\t\t\tEntry time: %s\n\n", p->BikeEntrytime);
        // printf("\t\t\t\t\t\t\tExit time: %s\n\n", p->BikeExittime);
        printf("\t\t\t\t\t\t\tBike Number :\t%s\n\n",Bikeplate);
        printf("\t\t\t\t\t\t\tPrice to Pay :\tRs %d\n",100*Bikehours);
        printf("\t\t\t\t-----------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t\t\tplease come again!!!\n\n\n");
        printf("\t\t\t\t\t\t\tpress ENTER to continue");
        getchar();getchar();
        system("cls");
    }
}
void BikeCost()
{
    printf("\n\n\n\n\n\t\t\t\t\t\tTotal money collected from Bike parking =  Rs %d \n\n",Bikecost);
    printf("\t\t\t\t\t\t\tpress ENTER to continue");
    getchar();getchar();
    system("cls");
}

void searchBike()
{
    char Bikenumb[20];
    int Bikecount=0;
    printf("\n\n\n\n\n\t\t\t\t\t\tBike plate number of the Bike to search: ");
    printf("\n\n\n\t\t\t\t\t\t");
    scanf("%s",Bikenumb);
    int Bikef=0;
    NODE* p=startBike;
    
    while(p!=NULL)
    {
        if(strstr(p->Bikeinfo,Bikenumb)!=NULL)
        {
            printf("\t\t\t\t\t\t\tParking slot: %d\n\n",p->BikeSlot);
            printf("\t\t\t\t\t\t\tBike Plate number: %s\n\n",p->Bikeinfo);
            printf("\t\t\t\t\t\t\tNo of hours for Parking:%d\n\n",p->BikeHours);
            printf("\t\t\t\t\t\t\tEntry time:%s\n\n",p->BikeEntrytime);
            printf("\n\n\n");
            Bikecount++;
        }

        p=p->Bikelink;
        Bikef=1;

    }
    
    if(Bikef==0)
    {
        printf("\n\n\n\t\t\t\t\t\tBIKE NOT FOUND!!!\n\n");
    }

    printf("\t\t\t\t\t\tSearch results found for %s = %d\n\n",Bikenumb,Bikecount);
    printf("\t\t\t\t\t\tpress ENTER to continue");
    getchar();getchar();
    system("cls");
}

int isvalidPlateNum(char* plateNumber)
{
    if(strlen(plateNumber)!=10){
        return 0;
    }
    
    for(int i=0; i<2;i++){
        if(!isalpha(plateNumber[i])){
            return 0;
        }
    }
    
    for(int i=2; i<4;i++){
        if(!isdigit(plateNumber[i])){
            return 0;
        }
    }
    
    for(int i=4; i<6;i++){
        if(!isalpha(plateNumber[i])){
            return 0;
        }
    }
        
    for(int i=6; i<10;i++){
        if(!isdigit(plateNumber[i])){
            return 0;
        }
    }

    return 1;
}

int isCarPlateRepeated(char *plateNumber)
{
    NODE *p = startcar;
    while (p != NULL)
    {
        if (strcmp(p->carinfo, plateNumber) == 0)
        {
            return 1;
        }
        p = p->carlink;
    }
    return 0;
}

int isBikePlateRepeated(char *plateNumber)
{
    NODE *p = startBike;
    while (p != NULL)
    {
        if (strcmp(p->Bikeinfo, plateNumber) == 0)
        {
            return 1;
        }
        p = p->Bikelink;
    }
    return 0;
}
