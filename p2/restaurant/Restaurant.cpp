#include <iostream>
#include "Restaurant.h"
#include "Table.h"
using namespace std;

Restaurant::Restaurant(int nLarge, int nMedium, int nSmall) : size(nLarge + nMedium + nSmall) {

    tableList = new Table*[size];

    for(int i = 0; i < nLarge ;++i){
        tableList[i] = new Table(10);
    }

    for(int i = nLarge; i < nMedium + nLarge;++i){
        tableList[i] = new Table(7);
    }

    for(int i = nMedium + nLarge; i < size;++i){
        tableList[i] = new Table(5);
    }

    //print
    for(int i = 0; i < size ; ++i){
        Table* table = tableList[i];
        cout << "Table " << i + 1 << " maximum occupancy " << table->maxOccupancy() << endl;
    }


}

void Restaurant::addGuests(int nGuests) {

    if (nGuests < 0 || nGuests == 0) {
        throw invalid_argument("must be positive");
    }else{
        for(int i = 0; i < size ;++i){
            Table* cTable = tableList[i];
            if(cTable->addGuests(nGuests)){
                cout << nGuests << " guests added to table " << (i+1) << endl;
                return;
            }
        }

        cout << " could not accommodate " << nGuests << " guests" << endl;
    }

}

void Restaurant::printSummary() {
    cout << "Summary:" << endl;
    for(int i = 0; i < size; ++i){
        if(tableList[i]->currentOccupancy() > 0){
            cout << "table " << (i + 1) << " " <<
                 tableList[i]->currentOccupancy() << "/" << tableList[i]->maxOccupancy() << endl;
        }

    }
}

