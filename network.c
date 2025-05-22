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
        strcpy(current_device->ip, ip_ptr);
        strcpy(current_device->hostname ,hn_ptr) ;

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

void display_connection2(struct device * current_device){

    while(current_device!=NULL){
        printf("%s ",current_device->hostname);
        if (current_device->next!=NULL){
            printf("==> ");
        }
        current_device =current_device->next;
    }
    printf ("\n");

}

void extend_connection(struct device *HeadDevice, struct device *new_device){

    
    while (HeadDevice->next!=NULL)
    {
        HeadDevice = HeadDevice->next;
    }
    HeadDevice->next=new_device;
}

void extend_connection2(struct device **HeadDevice_ptr, struct device *new_device){

    struct device * temp = * HeadDevice_ptr;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=new_device;
}



int main(){

    char ip1[] ={"1.1.1.1"};
    char hostname1[]= {"R1"};
    struct device * device1 = create_device (1,ip1,hostname1);

    char ip2[] ={"2.2.2.2"};
    char hostname2[]= {"R2"};
    struct device * device2 = create_device (2,ip2,hostname2);

    // device1->next=device2;
    extend_connection2(device1,device1);

    printf("%s  %s (%p) \n",device1->hostname,device2->hostname,device2);
    printf("%p  %p \n",device1->next,device2->next);
    // display_connection(&device1);
    display_connection2(device1);
    
    
    free(device1);
    free(device2);
    
    return 0;
}