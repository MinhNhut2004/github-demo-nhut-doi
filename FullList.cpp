#include <iostream>
using namespace std;
#define MaxLength 9
typedef int ElementType ;
typedef int Position;
struct List{
	ElementType element[MaxLength];
	Position Last;
};
void makenullList(List *L){
	L->Last=0;
}
int EmptyList(List L){
	if (L.Last==0) {
		return 1;
	}
	return 0;
}
int FullList(List L){
	if (L.Last==MaxLength){
		return 1;
	}
	return 0;
}
Position First(List L){
	return 1;
}
Position End(List L){
	return L.Last+1;
}
void InsertList(ElementType X , Position P, List *L){
	if (FullList(*L)){
		cout<<"Danh Sach Da Day";
	}
	else if (P < First(*L) || P > End(*L)){
		cout<<"Vi Tri Sai";
	}
	else {
		
		for (int Q=L->Last;Q>P;Q--){
			L->element[Q+1]=L->element[Q];
		}
		L->Last++;
		L->element[P]=X;
	}
}
void PrintList(List L){
	for (int i=First(L);i<End(L);i++){
		cout<<L.element[i];
		cout<<endl;
	}
}
void DeleteList(Position P, List *L){
	for (int Q=P;Q<End(*L);Q++){
		L->element[Q]=L->element[Q+1];
	}
	L->Last--;
}

ElementType Retrieve(Position P, List L){
	return L.element[P];
}
Position Next(Position P, List L){
	return  P+1;
}
void Locate (ElementType X, List L){
	Position P=First(L);
	while (P != End(L)){
		if (Retrieve(P,L)== X ){
			cout<<"phat hien "<<X<<" tai vi tri "<<P;
			return ; 
		}
		else P=Next(P,L);
	}
	cout<<"ko phat hien";
}
void InsertionSortDescending(List *L) {
    int n = L->Last;
    for (int i = 2; i <= n; i++) {
        ElementType key = L->element[i];
        Position j = i - 1;

        while (j >= 1 && L->element[j] < key) {
            L->element[j + 1] = L->element[j];
            j = j - 1;
        }
        L->element[j + 1] = key;
    }
}

int main(){
	List L; 
	// tao danh sach rong
	makenullList(&L);
	
	//kiem tra danh sach co rong khong
	if (EmptyList(L)) cout<<"Danh Sach Rong";
	else cout<<"Danh Sach Khong Rong";
	cout<<endl;
	
	
	//Chen Du Lieu 
	InsertList(1,1,&L);
	InsertList(2,2,&L);
	InsertList(3,3,&L);
	InsertList(4,4,&L);
	InsertList(0,5,&L);
	InsertList(6,6,&L);
	InsertList(7,7,&L);
	InsertList(8,8,&L);
	cout<<endl;
	
	
	//Kiem Tra Danh Sach Day Khong
	if (FullList(L)) cout<<"Danh Sach Da Day";
	else cout<<"Danh Sach Chua Day";
	cout<<endl;
	
	
	//in danh sach
	PrintList(L);
	cout<<endl;
	
	
	//xoa phan tu 
	DeleteList(3,&L);
	PrintList(L);
	
	int retrieve = Retrieve(4,L);
	cout<<"Vi Tri 4 la : "<<retrieve;
	
	cout<<endl;
	
	Locate(5,L);
	
	
	cout<<endl;
	PrintList(L);
	
	
}
