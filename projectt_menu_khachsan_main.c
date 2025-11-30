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

int themPhong(Room addRoom[], int roomCount){
	char id[5];
	int exist=-1;
	fflush(stdin);
	while(1){
	printf("Nhap ID phong: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, " \n")] = 0;

    if(strlen(id) == 0) {
        printf("ID khong duoc de rong!\n");
        continue;
    }
    
    for(int i=0; i<roomCount; i++){
    	if(strcmp(addRoom[i].room, id)==0){
    		exist =i;
    		break;
		}
	}
	if(exist !=-1){
		printf("Phong da ton tai!\n");
		return roomCount;
	}
	strcpy(addRoom[roomCount].room, id);
	do{
			printf("Nhap loai phong (1:Phong don, 2:Phong doi):");
			scanf("%d",&addRoom[roomCount].type);
			if(addRoom[roomCount].type!=1 && addRoom[roomCount].type!=2){
				printf("Phong khong hop le!\n");
			}
			}while(addRoom[roomCount].type!=1 && addRoom[roomCount].type!=2);
		
		do {
        printf("Nhap gia phong: ");
        scanf("%lf", &addRoom[roomCount].price);
        if (addRoom[roomCount].price < 0) {
            printf("Gia phong khong hop le!\n");
         }
         } while (addRoom[roomCount].price < 0);
			
			addRoom[roomCount].status=0;
			printf("Phong da duoc cap nhap!\n");
			return roomCount+1;
}
}
void capNhap(Room addRoom[], int roomCount){
	char update[5];
	int flag=-1;
	
	if (roomCount==0) {
        printf("Khong co phong nao!\n");
        return ;
    }
        
	printf("Nhap ID phong muon cap nhap:");
	scanf("%4s",update);
	getchar();

	for(int i=0; i<roomCount; i++){
		if(strcmp(update, addRoom[i].room)==0){
			flag =i;
			break;
		}
	}
	if(flag==-1){
		printf("Phong da ton tai hoac chua ton tai\n");
	}else{
		do{
			printf("Nhap loai phong moi(1:Phong don, 2:Phong doi):");
			scanf("%d",&addRoom[flag].type);
			if(addRoom[flag].type!=1 && addRoom[flag].type!=2){
			printf("Phong khong hop le!\n");
		}
			}while(addRoom[flag].type!=1 && addRoom[flag].type!=2);
			
			do{
			printf("Nhap gia phong moi:");
			scanf("%lf",&addRoom[flag].price);
			if(addRoom[flag].price <=0){
				printf("Gia tien khong hop le!");
			}
		    }while(addRoom[flag].price <=0);
			printf("Phong da duoc cap nhap!\n");
	}
}

void baoTriPhong(Room addRoom[], int roomCount){
		char baoTri[5];
			int flag =-1;
			if (roomCount==0) {
                printf("Khong co phong nao!\n");
                return ;
            }
			printf("Nhap phong muon bao tri:");
			scanf("%4s",baoTri);
			for(int i=0; i<roomCount; i++){
				if(strcmp(baoTri, addRoom[i].room)==0){
					flag =i;
					break;
				}
			}
			if(flag==-1){
				printf("Phong khong ton tai!\n");
			}else{
				if (addRoom[flag].status == 2){
            printf("Phong dang bao tri!\n");
            }else{
            addRoom[flag].status = 2;
            printf("Phong da chuyen sang trang thai bao tri!\n");
			}
		}
			
}
void hienThi(Room addRoom[],int roomCount){
    int perPage=3;       
    int totalPage=(roomCount+perPage-1)/perPage;
    int nowPage=1;
    char choose;

    if (roomCount==0) {
        printf("Khong co phong nao!\n");
        return ;
    }
    while(1){
    	system("cls");
        int start = (nowPage-1)*perPage;
        int end = start +perPage;
        if(end>roomCount){
        	end = roomCount;
		}
        printf("\n=============DANH SACH PHONG(%d/%d)============= \n",
               nowPage, totalPage);
        printf("|%-10s|%-10s|%-10s|%-12s|\n","ID Phong","The loai","Gia phong","Trang thai");
        printf("-------------------------------------------------\n");
        for (int i=start; i<end; i++){
            printf("|%-10s|",addRoom[i].room);
            if(addRoom[i].type==1)
                printf("%-10s|", "Phong Don");
            else
                printf("%-10s|", "Phong Doi");
            printf("%-10.0lf|", addRoom[i].price);
            if(addRoom[i].status==0){
                printf("%-12s|\n","Phong trong");
            }else if(addRoom[i].status==1){
                printf("%-12s|\n","Dang o");
            }else{
                printf("%-12s|\n","Bao tri");
            }
        }
        printf("----------------------------------------------\n");
        printf("F: FRONNT PAGE\n");
        printf("N: NEXT PAGE\n");
        printf("E: EXIT\n");
        printf("--------------------------------------------\n");
        printf("Nhap lua chon cua ban:");
        scanf(" %c",&choose);
        getchar();
        switch(choose){
        	case 'N' :
			case 'n' :
			{
        		if(nowPage< totalPage){
        			nowPage++;
				}else{
					printf("Ban dang o trang cuoi!!");
					printf("An enter de tiep tuc");
					getchar();
				}
				break;
			}
			case 'F' : 
			case 'f' :
				 {
				if(nowPage>1){
					nowPage--;
				}else{
					printf("Ban da o trang dau tien!!");
					printf("An enter de tiep tuc");
					getchar();
				}
				break;
			}
			case 'E':
			case 'e':
				{
				printf("Thoat khoi phan trang!!");
				printf("An enter de tiep tuc");
				getchar();                            
				return ;
				break;
			}
			default:{
				printf("Lua chon khong hop le!!!");
				printf("An enter de tiep tuc");
				getchar();
				break;
			}
		}
    }
}


void timKiem(Room addRoom[], int roomCount){
	int timPhong;
	int flag=0;
	if (roomCount==0){
        printf("Quay lai buoc 1 da nhe!\n");
        return ;
    }
	do{
	printf("Nhap loai phong muon tim kiem(1:phong don, 2:Phong doi):");
	scanf("%d",&timPhong);
	if(timPhong!=1 && timPhong!=2){
		printf("Phong ban muon tim khong hop le!\n"); 
	}
    }while(timPhong!=1 && timPhong!=2);
    
    
    system("cls"); 
	    printf("+----------------------------------------+\n");
		printf("|     Danh sach phong tim thay la        |");
		printf("\n+----------------------------------------+\n");
		printf("-----------------------------------------------\n");
		printf("|%-10s|%-10s|%-10s|%-12s|\n","ID Phong","The loai","Gia phong","Trang thai");
        printf("-----------------------------------------------\n");
        
        for(int i=0; i<roomCount; i++){
        	if(timPhong==addRoom[i].type && addRoom[i].status==0){
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
	if(flag==0){
		printf("Hien tai chua co phong phu hop!\n\n");
	}
}

void sapXep(Room addRoom[], int roomCount){
	if(roomCount==0){
		printf("Danh sach phong trong, khong the sap xep dau!\n");
		return;
	}
	for(int i=0; i<roomCount-1;i++){
		for(int j=0; j<roomCount-i-1;j++){
			if(addRoom[j+1].price > addRoom[j].price){
				Room temp=addRoom[j];
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
        }
int isLeapYear(int year){
    return(year % 400== 0) || (year % 4 == 0 && year % 100 != 0);
}
int isValidDate(char date[]){
    int d, m, y;
    int maxDay;
    if(strlen(date)!= 10){
	return 0;
    }
    if(date[2]!='/'|| date[5]!='/'){
    return 0;
    }
    sscanf(date,"%d/%d/%d", &d, &m, &y);

    if(d<=0 || m<=0 || y<=0){
	return 0;
    }
    if(m > 12){
	return 0;
    }
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDay = 31;
			 break;

        case 4: case 6: case 9: case 11:
            maxDay = 30;
			 break;

        case 2:
            if(isLeapYear(y))
                maxDay = 29;
            else
                maxDay = 28;
            break;

        default:
            return 0;
    }

    return d <= maxDay;
}


int checkIn(Booking books[], Room addRoom[], int roomCount, int bookCount){
    char roomId[5];
    char customerName[50];
    int days;
    char checkDate[20];
    int flag=-1;
    
    

    printf("Nhap ID phong muon booking: ");
    scanf("%4s", roomId);
    getchar();

    for(int i=0; i<roomCount; i++){
        if(strcmp(roomId, addRoom[i].room)==0){
            flag=i;
            break;
        }
    }

    if(flag==-1){
        printf("Loi! Khong co phong hop le\n");
        return bookCount;
    }

    if(addRoom[flag].status==1){
        printf("Phong da co khach ! Ban hay chon phong khac\n");
        return bookCount;
    }
    if(addRoom[flag].status==2){
        printf("Phong dang bao tri! Ban hay chon phong khac\n");
        return bookCount;
    }
    printf("Nhap ten khach hang: ");
    fgets(customerName, sizeof(customerName), stdin);
    customerName[strcspn(customerName, "\n")]=0;

    do{
        printf("Nhap so ngay o: ");
        scanf("%d", &days);
        getchar();
        if(days<=0){
            printf("So ngay khong hop le!\n");
        }
    } while(days<=0);

    do{
        printf("Nhap ngay nhan phong (DD/MM/YYYY): ");
        scanf("%19s", checkDate);
        if(!isValidDate(checkDate)){
            printf("Ngay khong hop le! Vui long nhap lai\n");
        }
    } while(!isValidDate(checkDate));

    
    books[bookCount].bookId = bookCount+1;
    strcpy(books[bookCount].roomId, roomId);
    strcpy(books[bookCount].customerName, customerName);
    books[bookCount].days = days;
    strcpy(books[bookCount].receiveDays, checkDate);
    books[bookCount].totalCost = days * addRoom[flag].price;

    addRoom[flag].status = 1;

    system("cls");
    printf("Chuc mung ban da check-in thanh cong!\n");
    printf("Ma Booking: %d\n", books[bookCount].bookId);
    printf("--------- HOA DON ----------\n");
    printf("Phong: %s\n", books[bookCount].roomId);
    printf("Khach hang: %s\n", books[bookCount].customerName);
    printf("So ngay o: %d\n", books[bookCount].days);
    printf("Ngay nhan phong: %s\n", books[bookCount].receiveDays);
    printf("Tong tien: %.0lf\n", books[bookCount].totalCost);

    return bookCount+1;
}

void historyRoom(Booking books[], int bookCount, Room rooms[], int roomCount){
    char roomId[5];
    int exist=0;
    
    printf("Nhap roomId muon xem lich su: ");
    scanf("%4s", roomId);

    for(int i = 0; i < roomCount; i++){
        if(strcmp(rooms[i].room, roomId)==0){
            exist=1;
            break;
        }
    }
    
    if(!exist){
        printf("Loi! Khong tim thay phong %s!\n", roomId);
        return;
    }
    
    system("cls");
    int found = 0;
    printf("\n======================== LICH SU THUE PHONG %s ========================\n", roomId);
    printf("|%-5s|%-20s|%-15s|%-15s|%-10s|\n", "STT", "Ten khach", "Ngay o", "Nhan phong", "Tong tien");
    printf("-----------------------------------------------------------------------\n");

    for(int i = 0; i < bookCount; i++){
        if(strcmp(books[i].roomId, roomId)==0){
            found++;
            printf("|%-5d|%-20s|%-15d|%-15s|%-10.0lf|\n",found, books[i].customerName,books[i].days,books[i].receiveDays,books[i].totalCost);
        }
    }
    if(found == 0){
        printf("Phong %s chua tung co khach thue!\n\n", roomId);
    }
}

int main(){
	Booking books[MAX];
	int bookCount=0;
	Room addRoom[MAX]={
	{"p1", 1, 500000, 1},
    {"p2", 2, 600000, 0},
    {"p3", 1, 450000, 0},
    {"p4", 2, 700000, 2},
    {"p5", 1, 550000, 0}
};
	int choose;
	int roomCount=5;
	
	while(1){
	printf("======================HE THONG CHUC NANG======================\n");
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
	
	printf("Moi nhap lua chon:");
	scanf(" %d",&choose);
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
			baoTriPhong(addRoom, roomCount);
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
			sapXep(addRoom,roomCount);
			break;
		}
		case 7:{
			bookCount=checkIn(books, addRoom, roomCount,bookCount);
			break;
		}
		case 8: {
            historyRoom(books, bookCount, addRoom, roomCount);
            break;
        }
        case 9:{
        	printf("Cam on ban da su dung chuong trinh! :3");
        	exit(0);
			break;
		}
		default:{
			printf("Lua chon cua ban khong hop le! Ban hay chon lai di!\n");
			break;
		}

	}
}
}

