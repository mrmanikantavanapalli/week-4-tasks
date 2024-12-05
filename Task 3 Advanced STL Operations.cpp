#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct control{
    int id;
    string type;
    string state;
};
int main() {
    vector<control> controls = {
         {1, "button", "visible"},
        {2, "slider", "invisible"},
        {3, "button", "disabled"},
        {4, "slider", "visible"},
        {5, "button", "visible"}
    };
    vector<control> copyControls(controls.size());
    copy(controls.begin(),controls.end(),copyControls.begin());
    
    vector<control> backupControls(controls.size());
    copy(controls.begin(),controls.end(),backupControls.begin());
    cout<<"backup of the control list : "<<endl;
    for (const control& bc : backupControls) {
    cout << "ID: " << bc.id << " Type: " << bc.type << " State: " << bc.state << endl;
    }
    
    control tempControl = {0,"","disabled"};
    fill(controls.begin(),controls.end(),tempControl);
    cout<<endl;
    cout<<"After setting all states to disabled temporarily"<<endl;
    for (const control& cc : copyControls) {
    cout << "ID: " << cc.id << " Type: " << cc.type << " State: " << tempControl.state << endl;
    }

    transform(copyControls.begin(),copyControls.end(),copyControls.begin(),[](control& copyControls){
        if(copyControls.type == "slider"){
        copyControls.state = "invisible";
        }
      return copyControls;
    });
    cout<<endl;
    cout<<"After changing the state of all sliders to invisible"<<endl;
      for (const control& cc : copyControls) {
    cout << "ID: " << cc.id << " Type: " << cc.type << " State: " << cc.state << endl;
    }
    
    cout<<endl;
     cout<<"After changing the state disabled to enabled"<<endl;
    for(control bc : backupControls){
        if(bc.state == "disabled"){
            bc.state = "enabled";
        }
            cout << "ID: " << bc.id << " Type: " << bc.type << " State: " << bc.state << endl;

    }
    
    backupControls.erase(
        remove_if(backupControls.begin(), backupControls.end(), [](const control& cc) {
            return cc.state == "invisible";
        }),
        backupControls.end()
    );

    cout << endl;
    cout << "After removing all 'invisible' controls:" << endl;
    for (const control& cc : backupControls) {
        cout << "ID: " << cc.id << " Type: " << cc.type << " State: " << cc.state << endl;
    }
    
    reverse(backupControls.begin(),backupControls.end());
    cout<<endl;
    cout<<"After reversing the control order:"<<endl;
    for (const control& bc : backupControls) {
        cout << "ID: " << bc.id << " Type: " << bc.type << " State: " << bc.state << endl;
    }
    
    return 0;
}