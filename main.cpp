#include "binary.tree.h"

int main(){
    Tree humano;
    humano.InsertValue(17);
    humano.InsertValue(15);
    humano.InsertValue(20);
    humano.InsertValue(10);
    humano.InsertValue(1);
    humano.InsertValue(11);
    
    humano.PreOrder(humano.GetRoot());
    cout<<" __________ "<<endl;
    humano.InOrder(humano.GetRoot());
    cout<<" __________ "<<endl;
    humano.PostOrder(humano.GetRoot());
    cout<<" __________ "<<endl;
    cout<<humano.GetNodeCounter()<<endl;
    cout<<" __________ "<<endl;
    cout<<humano.GetLarge()<<endl;
    cout<<" __________ "<<endl;
    cout<<humano.GetLargeByValue(10)<<endl;
    cout<<" __________ "<<endl;
    humano.DeleteElement(17);
    
    return 0;
}

















