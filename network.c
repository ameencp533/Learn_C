#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct device {
    int device_id;
    char ip[50];
    char hostname[50];
    struct device * next;

};


struct device * create_device(int id , char * ip_ptr , char * hn_ptr){

        struct device * current_device = (struct device *) malloc(sizeof(struct device ));

        current_device->device_id=id;
        strcpy(current_device->ip, *ip_ptr);
        strcpy(current_device->hostname ,*hn_ptr) ;

        current_device->next=NULL;

        return current_device;
        
        
}

void display_connection(struct device ** current_device_ptr){

    struct device * temp = *current_device_ptr;
    while(temp!=NULL){
        printf("%s ",temp->hostname);
        if (temp->next!=NULL){
            printf("==> ");
        }
        temp=temp->next;
    }

    printf ("\n");


}




int main(){

    char ip1[] ={"100.65.212.6"};
    char hostname1[]= {"R1"};
    struct device * device1 = create_device (1,ip1,hostname1);

    display_connection(&device1);

    free(device1);
    
    return 0;
}