/*This Program is Submitted by->
17_Shaivi Puranik
18_Siddhant Ram 
19_Sarthak Rane 
20_Anushka Rao 
Subject -> DSA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

//function prototype Admin
void displayInventory();
void mainAdmin();
void addToInventoryAdmin();
float calcTotalSalesAdmin();
void deleteFromInventoryAdmin();
void changeCostAdmin();
void changeQtyAdmin();

//function prototype Customer
struct Cart* createNode(int, int);
void AddToCart();
void DeleteFromCart();
void displayCart();
void displayBill();
void mainCustomer();
void deleteCart();

struct Cart
{
    int sr_no;
    char *name;
    int qtywant;
    float cost;
    struct Cart* next;
};

struct Cart *node, *head=NULL, *tail=NULL, *temp=NULL, *p=NULL, *q=NULL;

struct inventory
{
   char name[MAX];
   int sr_no;
   float cost;
   int qty;
};

struct inventory inven[MAX];
int count=3;

void main()
{
    int choice;
    inven[0].sr_no = 100;
    strcpy(inven[0].name,"Apple");
    inven[0].cost = 30;
    inven[0].qty = 20;
    inven[1].sr_no = 101;
    strcpy(inven[1].name, "Mango");
    inven[1].cost = 40;
    inven[1].qty = 20;
    inven[2].sr_no = 102;
    strcpy(inven[2].name, "Biscuits");
    inven[2].cost = 10;
    inven[2].qty = 20;
   
        do{
       
        printf("\n\n****** WELCOME TO SUPER DUPER SUPERMARKET *****");       
        printf("\n\tEnter 1 for admin or 2 for customer ->  ");
        scanf("%d", &choice);
       
        switch(choice)
        {
            case 0:
            break;
           
            case 1:
            mainAdmin();
            break;
           
            case 2:
            mainCustomer();
            break;
           
            default :
            printf("wrong");
            break;
        }
        
    }while(choice!=0);
   
    printf("\n\t\tThank you!");
}


struct Cart* createNode(int qtywant, int x)
{
        struct Cart *node = (struct Cart *)malloc(sizeof(struct Cart));
        node->sr_no = inven[x].sr_no;
        node->name = malloc(strlen(inven[x].name)+1);
        strcpy(node->name,inven[x].name);
        node->qtywant = qtywant;
        inven[x].qty = inven[x].qty - qtywant ;
        node->cost = inven[x].cost;
        node->next = NULL;
 
return node;
}


void AddToCart() //add at last operation
{
    int flag = 0;
    int searchsr_no, qtywant;
    int x=0, i=0;
   
    printf("\nEnter serial number of product to add in cart -> ");
    scanf("%d", &searchsr_no);

    for ( i=0 ; i<count ; i++)
    {
        if((searchsr_no)==(inven[i].sr_no))
        {
            flag=1;
            x = i;
        }
       
    }
   
   
     if(flag == 1)
    {
        printf("\n\t** Found **");
        printf("\tEnter quantity -> ");
        scanf("%d", &qtywant);
        if(qtywant > inven[x].qty)
        {
            printf("\nNot in stock, pls enter less qty");
        }
        else
        {
            node = createNode( qtywant, x);
            
            if(node!=NULL)
            {
                if(head==NULL)
                {
                   
                    head=node;
                    tail=node;
                    tail->next = NULL;
                    tail->qtywant = qtywant;
                }
                else
                {
                    tail->next = node;
                    tail = node;
                    tail->next = NULL;
                    tail->qtywant=qtywant;
                }
            }
        }   
    }

}




void DeleteFromCart()
{
    
    int searchsr_no;
    int flag=0;
    printf("\nEnter Serial Number of product to be deleted -> ");
    scanf("%d", &searchsr_no);
    
    if(head == NULL)
    {
        printf("Shopping cart is empty");
        printf("---------------------------------");
    }
    else
    {
        temp=head;
        p=temp;
        
        while(temp!=NULL)
        {
        
            if(searchsr_no == temp->sr_no)
            {
                flag=1;
                break;
            }
            p=temp;
            temp=temp->next;
            
        }
        
        if(flag == 1)
        {
            q=temp->next;
            p->next=q;
            free(temp);
            printf("\nProduct Deleted");
        }
    }
}

void displayCart()
{
    printf("\n Shopping cart ->\n");
    if (head == NULL)
    {
        printf("\t Empty :( ");
        printf("---------------------------------\n");
    }
    else
    {
        temp=head;
        char Name[20] = "Name";
        char Sr[20] = "Srno";
        char Cost[20] = "Cost";
        char Qty[20] = "QtyinStock";
        printf("%-5s|%-20s|%-15s|%-10s|\n", Sr, Name, Qty, Cost);
        printf("__________________________________________________\n");
   
        while (temp != NULL)
        {
            printf("%-5d|%-20s|%-15d|%-10g|", temp->sr_no, temp->name, temp->qtywant, (temp->cost)*(temp->qtywant));
            printf("\n");
            temp = temp->next;
        }
    }

}




void displayBill()
{   double discount;
    printf("\n Final Bill ->\n");
    
    float total=0;
    char Name[20] = "Name";
    char Sr[20] = "Srno";
    char Cost[20] = "Cost";
    char Qty[20] = "QtyinCart";
    printf("%-5s|%-20s|%-15s|%-10s|\n", Sr, Name, Qty, Cost);
    printf("__________________________________________________\n");
    
    if (head == NULL)
    {
        printf("---------------------------------");
        printf("Amount to pay = Rs. 0.0");
    }
    else
    {
        temp=head;
        while (temp != NULL)
        {
            printf("%-5d|%-20s|%-15d|%-10g|\n", temp->sr_no, temp->name, temp->qtywant, (temp->cost)*(temp->qtywant));
            printf("\n");
            total = total + ((temp->cost)*(temp->qtywant));
            temp = temp->next;
    
        }
    }
        
         if(total >= 500)
         {
                printf("Total amount is %.2f",total); 
                printf("\n\t\t\t\tHurray!! you got 5 percent discount!\n");
		        discount=total*0.05;
		        total=total-discount;
		        printf("Amount to pay = Rs. %g\n", total);
		        printf("\n\t\t\t\tThankyou for shopping");
      	 }
	
        else
        {
            printf("Amount to pay = Rs. %g\n", total);
            printf("\t\t\t\tThankyou for shopping\n");
        }
    
         deleteCart();
}


void deleteCart()
{
   do
    {
        head = head->next;
        free(temp);
        temp = head;
        
    }while(temp!=NULL);
    
    printf("\n\n\t\tReady for new customer");
    head = NULL;
    tail = NULL;
    
}

void displayInventory()
{
    printf("\n");
    char Name[20] = "Name";
    char Sr[20] = "Srno";
    char Cost[20] = "Cost";
    char Qty[20] = "QtyinStock";
    printf("%-5s|%-20s|%-15s|%-10s|\n", Sr, Name, Cost, Qty);
    printf("__________________________________________________\n");
    for(int i = 0; i < count; i++ )
    {
        printf("%-5d|%-20s|%-15g|%-10d|",inven[i].sr_no, inven[i].name, inven[i].cost, inven[i].qty);
        printf("\n");
    }

}


void addToInventoryAdmin()
{
    int add_num;
    printf("\nEnter nummber of items to be added -> ");
    scanf("%d", &add_num);
   
    for(int i = count; i < (count+add_num); i++ )
    {
        printf("\nEnter details of item %d\n", i+1);
       
        printf("Enter sr_no: ");
        scanf("%d", &inven[i].sr_no);
       
        printf("Enter name: ");
        scanf("%s", inven[i].name);

        printf("Enter cost: ");
        scanf("%f", &inven[i].cost);
        
        inven[i].qty=20;
      
    }
   
    count = count + add_num;
   
}

void deleteFromInventoryAdmin()
{
  int delsr_no;
 
        printf("Enter serial number of item to be deleted\t");
        scanf("%d", &delsr_no);
       
        for(int i=0;i<count;i++)
        {
            if(delsr_no == inven[i].sr_no)
            {  
                inven[i] = inven[i + 1];
                printf("\nItem deleted succefully\n\n");
                count--;
            }
        }
       
}

float calcTotalSalesAdmin()
{
    float total=0;
    printf("\n");
    char Name[20] = "Name";
    char Sr[20] = "Srno";
    char Cost[20] = "AmtSold";
    char Qty[20] = "QtySold";
    printf("%-5s|%-20s|%-15s|%-10s|\n", Sr, Name, Qty, Cost);
    printf("__________________________________________________\n");
    for(int i=0;i<count;i++)
    {
        printf("%-5d|%-20s|%-15d|%-10g|",inven[i].sr_no, inven[i].name, (20 - inven[i].qty), (inven[i].cost)*(20 - inven[i].qty) );
        printf("\n");
        total = total + (inven[i].cost)*(20 - inven[i].qty);
    }
   
    return total;
}

void changeCostAdmin()
{
    int changesr_no, flag;
    printf("\nEnter the serial number of item whose price is to be changed ->\t");
    scanf("%d", &changesr_no);
   
     for(int i=0;i<count;i++)
        {
            if(changesr_no == inven[i].sr_no)
            {  
                float newcost;
                printf("Item found, Name = %s \tCost = %g \n", inven[i].name, inven[i].cost);
                printf("Enter new cost ");
                scanf("%f", &newcost);
                inven[i].cost = newcost;
                printf("\nCost changed succefully\n\n");
                flag = 1;
            }
        }
       
        if (flag==0)
            {
                printf("\nItem with serial number %d Not found \n\n", changesr_no);
            }
}


void changeQtyAdmin()
{
     int changesr_no, flag;
     printf("\nEnter the serial number of item whose qty is to be changed ->\t");
    scanf("%d", &changesr_no);
     for(int i=0;i<count;i++)
        {
            if(changesr_no == inven[i].sr_no)
             {  
                int newQty;
                printf("Item found, Name = %s \tqty = %d \n", inven[i].name, inven[i].qty);
                printf("Enter new Qty");
                scanf("%d", &newQty);
                inven[i].qty= newQty;
                printf("\nQty changed succefully\n\n");
                flag = 1;
            }
        
        }
       
        if (flag==0)
            {
                printf("\nItem with serial number %d Not found \n\n", changesr_no);
            }
}
            
    
    
    
   
void mainAdmin()
{
    int choice;
    printf("\n\n****** SUPER DUPER SUPERMARKET *****");
    printf("\n\n****** WELCOME ADMIN *****");
    do{
        printf("\nEnter");
        printf("\n0 to go to main menu\n1 to add product in the inventory");
        printf("\n2 to display inventory");
        printf("\n3 to delete from inventory");
        printf("\n4 display total sales");
        printf("\n5 to change cost of any product \t   ");
         printf("\n6 to change Qty of any product \t -> ");
        scanf("%d", &choice);
       
        switch(choice)
        {
        case 0:
        break;
       
        case 1:
        addToInventoryAdmin();
        break;
       
        case 2:
        displayInventory();
        break;
       
        case 3:
        deleteFromInventoryAdmin();
        break;
       
        case 4:
        printf("**\tTotal sales done is -> Rs. %g \t**\n\n",calcTotalSalesAdmin());
        break;
       
        case 5:
        changeCostAdmin();
        break;
        
        case 6:
        changeQtyAdmin();
        break;
       
        default:
        printf("wrong");
        break;
        }
       
    }while(choice!=0);
   
    printf("***end Admin***");
   
}


void mainCustomer()
{
    int choice;
   
    printf("\n\n****** SUPER DUPER SUPERMARKET *****");
    printf("\n\n****** WELCOME NEW CUSTOMER *****");
    do{
        printf("\nEnter");
        printf("\n0 to go to main menu");
        printf("\n1 to add products to shopping cart");
        printf("\n2 to delete from shoping cart");
        printf("\n3 to display products in shopping cart ");
        printf("\n4 to display final bill ");
        printf("\n5 to display Inventory \t -> ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 0:
        break;
       
        case 1:
        AddToCart();
        break;
       
        case 2 :
        DeleteFromCart();
        break;
       
        case 3:
        displayCart();
        break;
       
        case 4:
        displayBill();
        break;
       
        case 5:
        displayInventory();
        break;
       
        default:
        printf("wrong");
        break;
        }
       
    }while(choice!=0);
   
    printf("**End Customer**");
}


//End of program