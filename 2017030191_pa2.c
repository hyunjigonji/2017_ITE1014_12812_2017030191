#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customInfo {
    char name[20];
    char phone_number[20];
    int id;
};

void addCustomer(struct customInfo *data, int *count_id, int *count);
void deleteCustomer(struct customInfo *data, int *count);
void searchCustomer(struct customInfo *data, int *count);
void dataScreen(struct customInfo *data, int *count);
void Result(struct customInfo *data, int *count, int index);
void Screen(char *input_select);
void searchPartCustomer(struct customInfo *data, int *count, int item);
int convert(char *str);
int Check(struct customInfo *data, int *count, struct customInfo input_new);
int searchWholeCustomer(struct customInfo *data, int *count, char *str);

int main() {
    struct customInfo data[150];
    int count = 0, count_id = 0;
    
    while (1) {
        char input_select;
        Screen(&input_select);
        
        if (input_select == '1') {
            addCustomer(data, &count_id, &count);
            dataScreen(data, &count);
        }
        else if (input_select == '2')
            deleteCustomer(data, &count);
        else if (input_select == '3')
            searchCustomer(data, &count);
        else if (input_select == '4')
            break;
    }
}

int convert(char *str) {
    int len = strlen(str), num = 0;
    for (int i = 2; i < len; i++)
        num = num * 10 + (str[i] - '0');
    
    return num;
}

int Check(struct customInfo *data, int *count, struct customInfo input_new) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(data[i].name, input_new.name) == 0 || strcmp(data[i].phone_number, input_new.phone_number) == 0)
            return 1;
    }
    return 0;
}

void Screen(char *input_select) {

    printf("%s\n", "1.사용자 추가");
    printf("%s\n", "2.사용자 제거");
    printf("%s\n", "3.사용자 검색");
    printf("%s\n", "4.프로그램 종료");
    printf("%s","입력 : ");
    scanf("%c", input_select);
    printf("\n");
    
    return;
}

void dataScreen(struct customInfo *data, int *count) {

    for (int i = 0; i < *count; i++) {
        printf("%s\n","사용자 정보");
        printf("%s : %s\n", "이름", data[i].name);
        printf("%s : %s\n", "전화번호", data[i].phone_number);
        printf("%s : %d\n", "id",data[i].id);
        printf("\n");
    }
    printf("Enter를 입력하세요");
    
    char c,cc;
    scanf("%c%c",&c,&cc);
    
    return;
}

void Result(struct customInfo *data, int *count, int index) {

    printf("%s\n", "검색 결과");
    printf("%s", "이름 : ");	printf("%s\n", data[index].name);
    printf("%s", "전화번호 : ");	printf("%s\n", data[index].phone_number);
    printf("%s", "아이디 : ");	printf("id%d\n", data[index].id);
    printf("Enter를 입력하세요");
    
    char c, cc;
    scanf("%c%c", &c, &cc);
    
    return;
}

void addCustomer(struct customInfo *data, int *count_id, int *count) {
    
    struct customInfo input_new;
    
    printf("%s\n", "1.사용자 추가");
    printf("%s", "이름 : ");
    scanf("%s", input_new.name);
    printf("%s", "전화번호 : ");
    scanf("%s", input_new.phone_number);
    printf("\n");
    
    if (Check(data, count, input_new)) {
        printf("%s\n", "이미 입력된 사용자입니다");
        printf("%s\n", "다시 입력하세요");
        char c, cc;
        scanf("%c%c", &c, &cc);
        addCustomer(data, count_id, count);
        return;
    }
    
    input_new.id = ++(*count_id);
    data[(*count)++] = input_new;
    
    return;
}

int searchWholeCustomer(struct customInfo *data, int *count, char *str) {
    if (48 <= str[0] && str[0] <= 57) {
        for (int i = 0; i < *count; i++) 	if (strcmp(str, data[i].phone_number) == 0) return i;
        return -1;
    }
    else if (str[0] == 'i' && str[1] == 'd') {
        int num = convert(str);
        for (int i = 0; i < *count; i++) if (num == data[i].id) return i;
        return -1;
    }
    else {
        for (int i = 0; i < *count; i++) if (strcmp(str, data[i].name) == 0) return i;
        return -1;
    }
}

void searchPartCustomer(struct customInfo *data, int *count, int item){
    printf("%s\n", "사용자 항목 검색 메뉴");
    
    char str[15];
    int flag = 0;
    
    if (item == 1) {
        printf("%s", "이름 : ");
        scanf("\n%s", str);
        for (int i = 0; i < *count; i++)
            if (strcmp(data[i].name, str) == 0) {
                Result(data, count, i);
                flag = 1;
            }
        if (flag == 0) {
            printf("\n%s\n", "사용자를 찾을 수 없습니다");
            printf("Enter를 입력한 후 다시 검색하세요");
            
            char c, cc;
            scanf("%c%c", &c, &cc);
            searchPartCustomer(data, count, item);	return;
        }
    }
    else if (item == 2) {
        printf("%s", "전화번호 : ");
        scanf("\n%s", str);
        for (int i = 0; i < *count; i++)
            if (strcmp(data[i].phone_number, str) == 0){
                Result(data, count, i);
                flag = 1;
            }
        if (flag == 0) {
            printf("\n%s\n", "사용자를 찾을 수 없습니다");
            printf("Enter를 입력한 후 다시 검색하세요");
            
            char c, cc;
            scanf("%c%c", &c, &cc);
            searchPartCustomer(data, count, item);	return;
        }
    }
    else if (item == 3) {
        printf("%s", "아이디 : ");
        scanf("\n%s", str);
        int num = convert(str);
        for (int i = 0; i < *count; i++)
            if (num == data[i].id){
                Result(data, count, i);
                flag = 1;
            }
        if (flag == 0) {
            printf("\n%s\n", "사용자를 찾을 수 없습니다");
            printf("Enter를 입력한 후 다시 검색하세요");
            
            char c, cc;
            scanf("%c%c", &c, &cc);
            searchPartCustomer(data, count, item);	return;
        }
    }
}

void deleteCustomer(struct customInfo *data, int *count){
    char str[15];
    
    if (*count == 0) {

        printf("\n%s\n", "저장된 정보가 없습니다");
        printf("Enter를 입력하세요");
        
        char c, cc;
        scanf("%c%c", &c, &cc);
        return;
    }
    
    printf("%s\n", "2.사용자 제거");
    printf("%s", "입력 : ");
    scanf("%s", str);
    
    int index =	searchWholeCustomer(data, count, str);
    
    if (index == -1) {
        printf("\n%s\n", "사용자를 찾을 수 없습니다");
        printf("Enter를 입력한 후 다시 검색하세요");
        
        char c, cc;
        scanf("%c%c", &c, &cc);
        deleteCustomer(data, count);
        return;
    }
    
    for (int i = index; i < (*count) - 1; i++)
        data[i] = data[i + 1];
    (*count)--;
    
    printf("\n%s\n", "사용자를 제거했습니다");
    printf("Enter를 입력하세요");
    
    char c, cc;
    scanf("%c%c", &c, &cc);
    
    return;
}

void searchCustomer(struct customInfo *data, int *count) {
    if (*count == 0) {
        printf("\n%s\n", "저장된 정보가 없습니다");
        printf("Enter를 입력하세요");
        
        char c, cc;
        scanf("%c%c", &c, &cc);
        return;
    }
    
    while (1) {
        printf("%s\n", "3.사용자 검색 메뉴");
        printf("%s\n", "1)전체 검색");
        printf("%s\n", "2)항목 검색");
        char c, str[15];
        printf("%s", "입력 : ");
        scanf("\n%c", &c);
        
        if (c == '1') {
            while (1) {
                printf("%s\n", "1)전체 검색");
                printf("%s", "입력 : ");
                scanf("\n%s", str);
                int index = searchWholeCustomer(data, count, str);
                if (index == -1) continue;
                else {
                    Result(data, count, index);
                    return;
                }
            }
        }
        else if (c == '2') {
            while (1) {
                printf("%s\n", "2)항목 검색");
                printf("%s\n", "\(1)이름");
                printf("%s\n", "\(2)전화번호");
                printf("%s\n", "\(3)아이디");
                printf("%s", "입력 : ");	scanf("\n%c", &c);
                if (c != '1' && c != '2' && c != '3') continue;
                searchPartCustomer(data, count, c-'0');   return;
            }
        }
    }
    
    return;
}
