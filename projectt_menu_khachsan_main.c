#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

typedef struct{
		char room[5];
		int type;
		double price;
		int status;
	}Room;

typedef struct{
		int bookId;
		char roomId[5];
		char customerName[50];
		int days;
		char receiveDays[20];
		double totalCost;
	}Booking;
	
int isNumber(char str[]){
		int i=0;
		if(str[i]=='\0' || str[i]=='\n'){
			return 0;
		}
		
		while(str[i]!='\0'){
			if(str[i]=='\n'){
				i++;
				continue;
			}
			if(str[i] <'0' || str[i] > '9'){
				return 0;
			}
			    i++;
		}
	return 1;
} 

int isOnlySpace(char str[]){
	int onlySpace=1;    // Ban dau chi la khoang trang
	
	for(int i=0; str[i] != '\0'; i++){
		if(str[i] !=' ' && str[i] != '\t'){
			onlySpace=0;
			break;
		}
	}
	return onlySpace; 
} 

int themPhong(Room addRoom[], int roomCount){
		char id[10];
		char themPhong[10];
		int flag=-1;
		
		while(1){
		printf("Nhap ID phong ban muon them vao:");
		fgets(id, sizeof(id), stdin);
		id[strcspn(id, "\n")]=0;               //xoa '\n'
		
		if(isOnlySpace(id)){                 //check
			printf("\n---------------------------\n");
			printf("| Ban khong duoc de rong! |");
			printf("\n---------------------------\n");
			continue;
		} 
		
		for(int i=0; i<roomCount; i++){                     
			if(strcmp(addRoom[i].room, id)==0){
				flag=i;
				break;
			}
		}
		if(flag!=-1){
			printf("\n---------------------\n");
			printf("| Phong da ton tai! |");
			printf("\n---------------------\n\n");
			return roomCount;
		}
		strcpy(addRoom[roomCount].room, id);
	
	do{
		printf("Nhap the loai phong (1: Phong don, 2 Phong doi):");
		fgets(themPhong, sizeof(themPhong), stdin);
		themPhong[strcspn(themPhong, "\n")]=0;
		
		if(isOnlySpace(themPhong)){                 
			printf("\n---------------------------\n");
			printf("| Ban khong duoc de rong! |");
			printf("\n---------------------------\n");
			continue;
		}
		addRoom[roomCount].type=atoi(themPhong);
		 
		if(addRoom[roomCount].type!=1 && addRoom[roomCount].type!=2){
			printf("\n----------------------------------------------------\n");
			printf("|Loai phong ban nhap vao khonng hop le! Nhap lai di|");
			printf("\n----------------------------------------------------\n\n");
		}
	}while(addRoom[roomCount].type!=1 && addRoom[roomCount].type!=2);
	
		while(1){
		char inputPrice[20];
		printf("Nhap gia phong:");
		fgets(inputPrice, sizeof(inputPrice), stdin);
		inputPrice[strcspn(inputPrice, "\n")]=0;
		
		if(isOnlySpace(inputPrice)){                 
			printf("\n---------------------------\n");
			printf("| Ban khong duoc de rong! |");
			printf("\n---------------------------\n");
			continue;
		}
		
		
		if(!isNumber(inputPrice)){
			printf("\n-------------------------------\n");
			printf("| Gia phong chi duoc nhap so! |");
			printf("\n-------------------------------\n\n");
			continue;
		}
		
		addRoom[roomCount].price= atof(inputPrice);      // chuyen doi chuoi nhap thanh so thuc
		
		if(addRoom[roomCount].price<=0){
			printf("\n--------------------------\n");
			printf("| Gia tien khong hop le! |");
			printf("\n--------------------------\n\n");
			continue;
		}
			break;
	    }
	    
	    addRoom[roomCount].status=0;
	    printf("\n-----------------------------------------\n");
	    printf("| Phong cua ban da cap nhat thanh cong! |");
	    printf("\n-----------------------------------------\n\n");
	    return roomCount+1;
	}
}

void capNhap(Room addRoom[], int roomCount){
	char update[10];
	char themPhong[10];
	int flag=-1;
	while(1){
		printf("Nhap ID phong muon cap nhap:");
		fgets(update, sizeof(update), stdin);
		update[strcspn(update, "\n")]=0;
			
		if(isOnlySpace(update)){                 
			printf("\n---------------------------\n");
			printf("| Ban khong duoc de rong! |");
			printf("\n---------------------------\n");
			continue;
		} 
		for(int i=0; i<roomCount; i++){
			if(strcmp(update, addRoom[i].room)==0){
				flag=i;
				break;
			}
		}
		if(flag==-1){
			printf("\n-------------------------------------\n");
			printf("| Khong tim thay phong de cap nhat! |");
			printf("\n-------------------------------------\n\n");
			continue;
		}
		do{
		printf("Nhap the loai phong moi(1: Phong don, 2:Phong doi):");
		fgets(themPhong, sizeof(themPhong), stdin);
		themPhong[strcspn(themPhong, "\n")]=0; 
		
		if(isOnlySpace(themPhong)){                 
			printf("\n---------------------------\n");
			printf("| Ban khong duoc de rong! |");
			printf("\n---------------------------\n");
			continue;
		}
		addRoom[flag].type=atoi(themPhong);
		
		if(addRoom[flag].type!=1 && addRoom[flag].type!=2){
			printf("\n----------------------------\n");
			printf("| Loai phong khong hop le! |");
			printf("\n----------------------------\n\n");
		}
	    }while(addRoom[flag].type!=1 && addRoom[flag].type!=2);
	    
	    char price[20];
	    while(1){
	    printf("Nhap gia tien moi:");
	    fgets(price, sizeof(price), stdin);
	    price[strcspn(price, "\n")]=0;
	    
	    if(isOnlySpace(price)){                 
			printf("\n---------------------------\n");
			printf("| Ban khong duoc de rong! |");
			printf("\n---------------------------\n");
			continue;
		}
	    
	    if(!isNumber(price)){
			printf("\n-------------------------------\n");
			printf("| Gia phong chi duoc nhap so! |");
			printf("\n-------------------------------\n\n");
			continue;
		}
		addRoom[flag].price= atof(price);
		
		if(addRoom[flag].price<=0){
		printf("\n--------------------------\n");
		printf("| Gia tien khong hop le! |");
		printf("\n--------------------------\n\n");
			continue;
		}
		break;
	    }
	    printf("\n---------------------------\n");
	    printf("| Phong da duoc cap nhat! |");
	    printf("\n---------------------------\n\n");
	    return;
	}
	
}

void baoTri(Room addRoom[], int roomCount){
		char bt[10];
		int flag=-1;
		do{
		printf("Nhap ID phong muon bao tri:");
		fgets(bt, sizeof(bt), stdin);
		bt[strcspn(bt, "\n")]=0;
		
		if(isOnlySpace(bt)){                 
			printf("\n---------------------------\n");
			printf("| Ban khong duoc de rong! |");
			printf("\n---------------------------\n");
		} 
		}while(isOnlySpace(bt));
		
		
		for(int i=0; i<roomCount; i++){
			if(strcmp(bt, addRoom[i].room)==0){
				flag=i;
				break;
			}
		}
		
		if(flag==-1){
			printf("\n----------------------\n");
			printf("|Phong khong ton tai!|");
			printf("\n----------------------\n\n");
		}else{
			if(addRoom[flag].status == 1){
				printf("\n--------------------------------------------------------------\n");
				printf("| Phong da co nguoi o! Khong the dua vao trang thai bao tri! |");
				printf("\n--------------------------------------------------------------\n\n");
			}else if(addRoom[flag].status == 2){
				printf("\n----------------------------------------\n");
				printf("| Phong dang trong trang thai bao tri! |");
				printf("\n----------------------------------------\n\n");
			}else{
				addRoom[flag].status =2;
				printf("\n--------------------------------------------\n");
				printf("| Phong da chuyen sang trang thai bao tri! |");
				printf("\n--------------------------------------------\n\n");
			}
		}
		
	}

void hienThi(Room addRoom[], int roomCount){
	int perPage=3;
	int totalPage=(roomCount+perPage-1)/perPage;
	int nowPage=1;
	char choose;
	
		while(1){
		system("cls");
		int start=(nowPage-1)*perPage;
		int end=start+perPage;
		if(end>roomCount){
			end=roomCount;
		}
		printf("\n=============DANH SACH PHONG(%d/%d)============= \n",nowPage, totalPage);
		printf("|%-10s|%-10s|%-10s|%-12s|\n","ID Phong","The Loai","Gia Phong","Trang thai");
		printf("-----------------------------------------------\n");
		
		for(int i=start; i<end; i++){
			printf("|%-10s|",addRoom[i].room);
			if(addRoom[i].type==1){
				printf("%-10s|","Phong don");
			}else{
				printf("%-10s|","Phong doi");
			}
			
			printf("%-10.0lf|",addRoom[i].price);
			if(addRoom[i].status==0){
				printf("%-12s|\n","Phong trong");
			}else if(addRoom[i].status==1){
				printf("%-12s|\n","Dang o");
			}else{
				printf("%-12s|\n","Bao tri");
			}
		}
			printf("-----------------------------------------------\n");
			printf("F: Trang ke tiep\n");
			printf("B: Trang sau\n");
			printf("E: Thoat\n");
			printf("-----------------------------------------------\n");
			printf("Nhap lua chon cua ban:");
			scanf(" %c",&choose);
		
		switch(choose){
			case 'F':
			case 'f':
			{
				if(nowPage<totalPage){
					nowPage++;              
				}else{
					printf("Ban dang o trang cuoi!!");
					printf("An enter de tiep tuc!");
					getchar();getchar();          
				}
				break; 
			}
			case 'B' : 
			case 'b' :
				 {
				if(nowPage>1){
					nowPage--;
				}else{
					printf("Ban da o trang dau tien!!");
					printf("An enter de tiep tuc");
					getchar();getchar();
				}
				break;
			}
			case 'E':
			case 'e':
				{
				printf("Thoat khoi phan trang!!\n");
				printf("An enter de tiep tuc!\n");
				getchar();getchar();                        
				return ;
				break;
			}
			default:{
				printf("Lua chon khong hop le!!!");
				printf("An enter de tiep tuc");
				getchar();getchar(); 
				break;
			}
			
		}
     }
	
}

void timKiem(Room addRoom[], int roomCount){
	char input[100];
    int tp;
    int flag=0; 

    do {
        printf("Nhap loai phong ban muon tim kiem(1:Phong don, 2:Phong doi): ");
        fgets(input, sizeof(input), stdin);
        if(isOnlySpace(input)){                 
            printf("\n---------------------------\n");
            printf("| Ban khong duoc de rong! |\n");
            printf("---------------------------\n");
            continue;
        } 

        tp = atoi(input);  //chuyen chuoi sang int 

        if(tp != 1 && tp != 2){
            printf("Phong ban muon tim khong hop le!!\n");
        }

    } while(tp != 1 && tp != 2);
	
	system("cls"); 
	    printf("+----------------------------------------+\n");
		printf("|     Danh sach phong tim thay la        |");
		printf("\n+----------------------------------------+\n");
		printf("-----------------------------------------------\n");
		printf("|%-10s|%-10s|%-10s|%-12s|\n","ID Phong","The loai","Gia phong","Trang thai");
        printf("-----------------------------------------------\n");
        
        for(int i=0; i<roomCount; i++){
        	if(tp==addRoom[i].type && addRoom[i].status==0){
        		flag =1;
        		printf("|%-10s|",addRoom[i].room);
            if(addRoom[i].type==1){
                printf("%-10s|", "Phong Don");
            }else{
                printf("%-10s|", "Phong Doi");
        }
          printf("%-10.0lf|", addRoom[i].price);
          
            if(addRoom[i].status==0){
                printf("%-12s|\n","Phong trong");
            }
			}
		}
		 printf("-----------------------------------------------\n");
	if(flag==0){
		printf("Hien tai chua co phong phu hop!\n\n");
	}
}

void sapXep(Room addRoom[], int roomCount){
	for(int i=0; i<roomCount-1; i++){
		for(int j=0; j<roomCount-i-1; j++){                
			if(addRoom[j+1].price > addRoom[j].price){
				Room temp = addRoom[j];                     
				addRoom[j]=addRoom[j+1];
				addRoom[j+1]=temp;
			}
		}
	}
	system("cls");
	printf("+----------------------------------------+\n");
	printf("|     Danh sach phong sau khi sap xep    |");
	printf("\n+----------------------------------------+\n");
		printf("-----------------------------------------------\n");
		printf("|%-10s|%-10s|%-10s|%-12s|\n","ID Phong","The loai","Gia phong","Trang thai");
        printf("-----------------------------------------------\n");
        
		for (int i=0; i<roomCount; i++){
            printf("|%-10s|",addRoom[i].room);
            if(addRoom[i].type==1){
                printf("%-10s|", "Phong Don");
            }else{
                printf("%-10s|", "Phong Doi");
        }
          printf("%-10.0lf|", addRoom[i].price);
          
            if(addRoom[i].status==0){
                printf("%-12s|\n","Phong trong");
            }else if(addRoom[i].status==1){
                printf("%-12s|\n","Dang o");
            }else{
                printf("%-12s|\n","Bao tri");
            }
			}
			printf("-----------------------------------------------\n");
			printf("Nhan enter de tiep tuc!"); 
			getchar();
}

int isValidName(char name[]){
	for(int i=0; name[i]!='\0'; i++){
		if(!((name[i] >='A' && name[i]<= 'Z') || 
		(name[i] >= 'a' && name[i] <= 'z')|| 
		(name[i]==' '))){
			return 0; 
		}
	}
	return 1; 
}

int leapYear(int year){
	if((year % 400== 0) || (year % 4 == 0 && year % 100 != 0)){
		return 1;
	}else{
		return 0;
	}
} 

int isValidDate(char date[]){
		int d,m,y;
		int maxDay;
		
		if(strlen(date)!=10){
			return 0;
		}
		
		if(date[2] != '/' || date[5] !='/'){
			return 0;
		}
		
		sscanf(date,"%d/%d/%d",&d,&m,&y);
		
		if(d<=0 || m<=0 ||y<=0){
			return 0;
		}
		if(m>12){
			return 0;
		}
		switch(m){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				maxDay=31;
				break;
				
			case 4: case 6: case 9: case 11:
				maxDay=30;
				break;
			case 2:
				if(leapYear(y)){
					maxDay=29;
				}else{
					maxDay=28;
				}                                                                    
				break;
			default:
				return 0;
				
		}
		if(d > maxDay){
			return 0;
		}
		return 1;
}

int checkIn(Booking books[], int bookCount, int roomCount, Room addRoom[]){
		char roomId[10];
		char customerName[50];
		char days[10];
		char checkDate[20];
		int flag=-1;
		int day; 
	
	while(1){
	printf("Nhap ID phong ban muon dat:");
	fgets(roomId, sizeof(roomId), stdin);
	roomId[strcspn(roomId, "\n")]=0;
	
	if(isOnlySpace(roomId)){
            printf("\n---------------------------\n");
            printf("| Ban khong duoc de rong! |\n");
            printf("---------------------------\n");
            continue;
        }
    
    for(int i=0; i<roomCount; i++){
    	if(strcmp(roomId, addRoom[i].room)==0){
    		flag=i;
    		break;
		}
	}
	if(flag==-1){
		printf("\n-------------------------\n");
		printf("| Khong tim thay phong! |");
		printf("\n-------------------------\n");
		continue; 
	}
	if(addRoom[flag].status==1){
		printf("\n------------------------------------------------\n");
		printf("| Phong da co khach! Ban hay chon phong khac |");
		printf("\n------------------------------------------------\n");
		continue;
		 
	}else if(addRoom[flag].status==2){
		printf("\n------------------------------------------------\n");
		printf("| Phong dang bao tri! Ban hay chon phong khac |");
		printf("\n------------------------------------------------\n");
		continue; 
	}
	break; 
}
	do{
		printf("Nhap ten khach hang:");
		fgets(customerName, sizeof(customerName), stdin);
		customerName[strcspn(customerName, "\n")]=0;
		
		if(!isValidName(customerName)){
			printf("\n------------------------------\n");
			printf("| Ten ban nhap khong hop le! |");
			printf("\n------------------------------\n\n");
		}
	}while(!isValidName(customerName));
	
		printf("Nhap so ngay o:");
		fgets(days, sizeof(days), stdin);
        days[strcspn(days, "\n")] = 0;
		
		if(!isNumber(days)){
			printf("\n------------------------------\n");
			printf("| So ngay nhap khong hop le! |");
			printf("\n------------------------------\n");
			return bookCount;
		}
		day= atoi(days);  
		
		if(day <= 0){
			printf("\n----------------------------------------------------\n");
			printf("| So ngay nhap khong hop le! Ngay o phai lon hon 0 |");
			printf("\n----------------------------------------------------\n");
			return bookCount;
		}
		
	do{
		printf("Nhap ngay thang nhan phong (DD/MM/YYYY):");
		fgets(checkDate, sizeof(checkDate), stdin);
		checkDate[strcspn(checkDate, "\n")]=0;
		if(!(isValidDate(checkDate))){
			printf("\n--------------------------------------------\n");
			printf("| Ngay ban nhap khong hop le! Hay nhap lai |");
		    printf("\n--------------------------------------------\n\n");
		}
	}while(!(isValidDate(checkDate)));
	
	books[bookCount].bookId=bookCount+1;
	strcpy(books[bookCount].roomId, roomId);
	strcpy(books[bookCount].customerName, customerName);
	books[bookCount].days=day; 
	strcpy(books[bookCount].receiveDays, checkDate);
	books[bookCount].totalCost= (double)day *addRoom[flag].price;        // ep day thanh double 
	
	addRoom[flag].status=1;
	
	system("cls");
	printf("Chuc mung ban da check-in thanh cong!\n");
    printf("Ma Booking: %d\n", books[bookCount].bookId);
    printf("-------------- HOA DON --------------\n");
    printf("Phong: %s\n", books[bookCount].roomId);
    printf("Khach hang: %s\n", books[bookCount].customerName);
    printf("So ngay o: %d\n", books[bookCount].days);
    printf("Ngay nhan phong: %s\n", books[bookCount].receiveDays);
    printf("Tong tien: %.0lf\n", books[bookCount].totalCost);
    printf("--------------------------------------\n\n");
    return bookCount+1;
}

void lichSu(Booking books[], int bookCount, int roomCount, Room addRoom[]){
	char historyRoom[10];
	int flag=-1;
	

		printf("Nhap ID phong muon xem lich su:");
		fgets(historyRoom, sizeof(historyRoom), stdin);
		historyRoom[strcspn(historyRoom, "\n")]=0;
		
		for(int i=0; i<roomCount; i++){
			if(strcmp(historyRoom, addRoom[i].room)==0){
				flag=i;
				break;
			}
		}
		if(flag==-1){
		printf("\n-------------------------\n");
		printf("| Khong tim thay phong! |");
		printf("\n-------------------------\n");
		return;                                                      
		}
		system("cls");
		int found=0;
		printf("\n======================== LICH SU THUE PHONG %s ========================\n",historyRoom);
	    printf("|%-5s|%-20s|%-15s|%-15s|%-10s|\n", "STT", "Ten khach", "Ngay o", "Nhan phong", "Tong tien");
	    printf("-----------------------------------------------------------------------\n");
	    
	    for(int i=0; i<bookCount; i++){
	    	if(strcmp(historyRoom, books[i].roomId)==0){
	    		found++;
	    		printf("|%-5d|%-20s|%-15d|%-15s|%-10.0lf|",found,books[i].customerName,books[i].days,books[i].receiveDays,books[i].totalCost);
			}
		}
		printf("\n-----------------------------------------------------------------------\n");
		if(found==0){
			printf("\n---------------------------------------\n");
			printf("| Phong chua chua tung co khach thue! |");
			printf("\n---------------------------------------\n\n");
		}
		
}

int main(){
		Booking books[MAX];
		int bookCount=0;
		int choose;
		int roomCount=5;
		Room addRoom[MAX]={
		{"p1", 1, 500000, 1},
	    {"p2", 2, 600000, 0},
	    {"p3", 1, 450000, 0},
	    {"p4", 2, 700000, 2},
	    {"p5", 1, 550000, 0}
	};
	while(1){
		printf("\n---------------------DANH SACH CHUC NANG--------------------\n");
		printf("1. (F01): Them phong moi\n");
		printf("2. (F02): Cap nhat phong\n");
		printf("3. (F03): Bao tri phong\n");
		printf("4. (F04): Hien thi danh sach\n");
		printf("5. (F05): Tim kiem\n");
		printf("6. (FO6): Sap xep danh sach phong\n");
		printf("7. (F07): Check-in (giao dich nhan phong)\n");
		printf("8. (F08): Lich su thue\n");
		printf("9. (F09): Thoat he thong\n");
		printf("================================================================\n");
		
		char input[20];
		while(1){
			printf("Nhap lua chon cua ban:");
			fgets(input, sizeof(input), stdin);
			input[strcspn(input, "\n")]=0;
			
			if(!isNumber(input)){
				printf("\n------------------------------\n");
		        printf("| Lua chon khong hop le !!! |\n");
		        printf("------------------------------\n\n");
		        continue;
			}
			choose=atoi(input);
			break;
		}
		switch(choose){
			case 1:{
				roomCount = themPhong(addRoom, roomCount);
				break;
			}
			case 2:{
				capNhap(addRoom, roomCount);
				break;
			}
			case 3:{
				baoTri(addRoom, roomCount);
				break;
			}
			case 4:{
				hienThi(addRoom, roomCount);
				break;
			} 
			case 5:{
				timKiem(addRoom, roomCount);
				break;
			}
			case 6:{
				sapXep(addRoom, roomCount); 
				break;
			}
			case 7:{
				checkIn(books, bookCount, roomCount, addRoom);
				break;
			} 
			case 8:{
				lichSu(books, bookCount, roomCount, addRoom);
				break;
			}
			case 9:{
				printf("\n-------------------------------------------\n");
				printf("Cam on ban da su dung chuong trinh!\n");
				printf("-------------------------------------------\n");
				exit(0);
				break;
			}
			default:{
				printf("------------------------------\n");
				printf("Ban nhap khong hop le!\n");
				printf("------------------------------\n");
				break;
			}
		}
	}
}
		
	

