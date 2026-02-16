#include <iostream>
using namespace std;

int main() {
    char again;

    do {
        const int SALESPEOPLE = 4;
        const int PRODUCTS = 5;

        double sales[PRODUCTS][SALESPEOPLE] = {0};

        int sp, prod;
        double amt;
        char cont;

        do {
            cout << "Salesperson (1-4): ";
            cin >> sp;
            cout << "Product (1-5): ";
            cin >> prod;
            cout << "Amount: ";
            cin >> amt;

            if (sp>=1 && sp<=4 && prod>=1 && prod<=5)
                sales[prod-1][sp-1]+=amt;

            cout << "Add another entry? (y/n): ";
            cin >> cont;

        } while(cont=='y'||cont=='Y');

        for(int i=0;i<SALESPEOPLE+2;i++)
            cout<<"---------";
        cout<<endl;

        cout<<"| Prod |";
        for(int s=0;s<SALESPEOPLE;s++)
            cout<<" S"<<s+1<<"   |";
        cout<<" Total |\n";

        for(int i=0;i<SALESPEOPLE+2;i++)
            cout<<"---------";
        cout<<endl;

        double colTotal[SALESPEOPLE]={0};
        double grand=0;

        for(int i=0;i<PRODUCTS;i++){
            double rowTotal=0;
            cout<<"|  "<<i+1<<"   |";

            for(int j=0;j<SALESPEOPLE;j++){
                cout<<" "<<sales[i][j]<<" |";
                rowTotal+=sales[i][j];
                colTotal[j]+=sales[i][j];
            }

            cout<<" "<<rowTotal<<" |\n";
            grand+=rowTotal;
        }

        for(int i=0;i<SALESPEOPLE+2;i++)
            cout<<"---------";
        cout<<endl;
        
        cout<<"| Tot  |";
        for(int j=0;j<SALESPEOPLE;j++)
            cout<<" "<<colTotal[j]<<" |";
        cout<<" "<<grand<<" |\n";

        for(int i=0;i<SALESPEOPLE+2;i++)
            cout<<"---------";
        cout<<endl;

        cout<<"\nRun again? (y/n): ";
        cin>>again;

    } while(again=='y'||again=='Y');

    return 0;
}