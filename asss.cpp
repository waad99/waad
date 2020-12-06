/*
My name: waad osama
class: seconde 
Department: computer 
*/
#include <iostream>
#include<cassert>
using namespace std;
#include<string>

//LINKED_LIST Area..
class linkedList{  //تعريف كلاس خاص بالقوائم المتصلة 
    struct Node{ 
        int ietm; //تعريف خواص الكلاس
        Node*next; // يشير الي العنصر اللاحق في القائمة
    };
    Node*head; //يشير الي رأس القائمة
    Node*tail; //يشير الي ذيل القائمة
    int length; //تعريف متغير للمساعدة علي عملية الحذف والاضافة وتتبع العناصر
public:
    linkedList(){
        head = tail = NULL; //جعل الذيل يشير الي عنصر افتراضي 
        length = 0; //وضع الموشر علي بداية القائمة
    }
    bool isEmpty(){ //عمل دالة للتحقق من اذا ماكانت القائمة تحوي عناصر ام لا
        return length == 0; // "true"اذا كانت تحوي عناصر سترجع 1 واذا كانت فارغة سترجع الدالة
    }
    void insert_Head(int Element){ //عمل دالة مهمتها اضافة عنصر عند رأس القائمة
        Node*newNode = new Node;
        newNode->ietm = Element;
        if (length == 0){
            head = tail = newNode;
            newNode->next = NULL;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        length++;
        
    }
    void insert_Tail(int Element){ //عمل دالة مهمتها اضافة عنصر عند ذيل القائمة
        Node*newNode = new Node;
        newNode->ietm = Element;
        if (length == 0){
            head = tail = newNode;
            newNode->next = NULL;
        }
        else{
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
        length++;
    }
    void insertAtpos(int pos,int Element){ //عمل دالة لاضافة عنصر عند اي موضع يريده المستخدم
        if (pos<0 || pos>length){
            cout<< "out of Range ";
        }
        else
        {
            Node*newNode = new Node;
            newNode->ietm = Element;
            if(pos==0)
                insert_Head(Element);
            else if(pos == length)
                insert_Tail(Element);
            else
            {
                Node * Cur = head;
                for (size_t i = 0; 1 < pos; i++)
                {
                    Cur = Cur->next;
                }
                newNode->next = Cur->next;
                Cur->next = newNode;
                length++;
            }   
        }   
    }
    void removeHead(){ //عمل دالة للحذف من رأس القائمة
        if (length == 0)
        cout<< "Empty list can not Remove"<<endl;
        else if(length == 1){
            delete head;
            tail = head = NULL;
            length--;
        }
        else
        {
            Node*Cur= head;
            head = head->next;
            delete Cur;
            length--;
        }  
    }
    void removeTail(){ //عمل دالة للحذف من ذيل القائمة
        Node * Cur = head->next;
        Node*prev = head;
        while (Cur != tail)
        {
            prev = Cur;
            Cur = Cur->next;
        }
        delete Cur;
        prev->next = NULL;
        tail = prev;
        length--;
    }
    void remove(int Element){ //دالة مهمتها العنصر الذي يريد المستخدم حذفه
        if(isEmpty()){
            cout<<"Empty list can not Remove ";
            return;
        }
        Node*Cur,*prev;
        if (head->ietm == Element){
            Cur = head;
            head = head->next;
            while(Cur != NULL){
                if (Cur->ietm == Element)
                    break;
                prev = Cur;
                Cur = Cur->next;
            }
            if (Cur == NULL)
                cout<< "The Elment not Found ";
            else{
                prev->next = Cur->next;
                if(tail == Cur){
                    tail = prev;
                delete Cur;
                length--;
                }
                
            }
            
        }
    }
    void print(){ // دالة مهمتها طباعة عناصر القائمة
        Node * cur = head;
        while (cur != NULL)
        {
            cout<<cur->ietm<<" ";
            cur = cur->next;
        }
        
    }
};

//STACK Arae..
const int Max_size = 5; //تعيين حد أعلي للمكدس مقداره 5 عناصر
class Stack{ //تعريف كلاس خاص بالمكدس
    int top; //تعريف متغير مساعد للمساعدة في عمليتي الحذف والاضافة وتتبع العناصر ايضا
    int StackArr[Max_size]; //استخدام المصفوفات مع المكدس وتعيين قيمة المصفوفة وجعلها تساوي قيمة عناصر المكدس
public:
    Stack(){
        top = -1; // جعله بسالب واحد لكي تبدأ الاضافة منه
    }
    void push(int Element){ //دالة مهمتها دفع العنصر المطلوب ادخاله الي المكدس
        if (top >= Max_size -1){
            cout<<"Stack Overflow"; //عبارة تعني أن المكدس ممتلئ ولاتمكن الاضافة عليه
        }
        else{
        top++; //شرط معناه لو لم يكن المكدس ممتلئ قم بالأضافة
        StackArr[top] = Element; //جعل العنصر الذي تم ادخاله يساوي اخر قيمة في المصفوفة
        }
    }
    bool isEmpty(){ //دالة مهمتها التحقق مااذا كان المكدس فارغ ام ال
        return top < 0;
    }
    void pop(){ // دالة مهمتها الحذف من المكدس
         if (isEmpty())
             cout << "Stack Underflow"; // اذا كان المكدس فارغ تخرج عبارة توضح ان المكدس لايمكن الحذف منه لانه فارغ
        else
            top--; // اذا لمن يكن فارغ قم بعملية الحذف بصورة عادية
        
    }

    void pop(int&Element){
         if (isEmpty())
             cout << "Stack Underflow";
        else{
            Element = StackArr[top];
            top--;
        }
    }

    void getTop(int&StackTop){ //دالة مهمتها ايجاد اخر عنصر تم ادخاله الي المكدس
         if (isEmpty())
             cout << "Stack empty on getTop"; // لو كان المكدس فارغ سيكون العنصر الاخير هو فراغ المكدس
        else{
            StackTop = StackArr[top];
            cout << StackTop <<endl; //لو لم يكن المكدس فارغ قم بطباعة اخر عنصر تم ادخاله
        }
    }
    void print() { //دالة مهمتها طباعة عناصر المكدس
        cout<<"[";
        for (int i = top; i >= 0; i--){
            cout<< StackArr[i]<< " ";

        }
        cout << "]";
        cout << endl;

    }
};
//QUEUE Area..
const int Max_Length = 5; //تعيين حد اقصي للعناصر التي يمكن ادخاله الي الطابور مقداره 5 عناصر
class Queue{ //عمل كلاس خاص بالطوابير
    int rear; //تعريف مؤخرة الطابور
    int front; // تعريف مقدمة الطابور
    int count; //تعريف متغير مهمته السماعدة علي الحذف من والأضافة الي الطابور وتتبع العناصر ايضا
    int arr[Max_Length]; //استخدام المصفوفات مع الطابور واعطاءها اقصي قيمة للطابور
public:
    Queue(){
        front = 0;
        rear = Max_Length - 1;
        count = 0;
    }
    int isEmpty(){ //دالة مهمتها التحقق مااذا كان الطابور فارغ
        return count == 0;
    }
    bool isFull(){ //دالة مهمتها التحقق مااذا كان الطابور ممتلئ 
        return count == Max_Length;
    }
    void enQueue(int Element){ // دالة تمكننا من اضافة العناصر الي الطابور
        if (isFull()){ 
            cout<<"Queue Full can not EnQueue ..."; //اذا كان كان الطابور ممتلئ اطبع رسالة توضح ان الطابور لايمكن الاضافة عليه
        }
        else{ //غير ذلك قم بالأ1افة بشكل عادي

            rear = (rear + 1) % Max_Length;
            arr[rear] = Element;
            count++;
        }
        
    }
    void deQueue(){ //دالة تعمل علي حذف العناصر من الطابور
        if(isEmpty()){
            cout<< "Empty Queue can not DeQueue ..."; //اذا كان الطابور فارغ اطبع رسالة توضح ان الطابور فارغ لايمكن الحذف من
        }
        else{ //غير ذلك قم بعملية الحذف
            front = (front + 1) % Max_Length;
            --count;
        }
        
    }
    int getFront(){ //دالة مهمتها ايجاد العنصر الذي في مقدمة الطابور
        assert(!isEmpty()); //بالاستفادة من دالة التحقق من خواء الطابور القيام بارجاع القيمة التي في مقدمة المصفوفة
        return arr[front]; 
    }
    int getRear(){ //دالة مهمتها ايجاد العنصصر الذي في موخرة الطابور
        assert(!isEmpty()); //بالأستفادة من دالة التحقق من خواء الطابور القيام بارجاع القيمة المتمثلة في مؤخرة المصفوفة
        return arr[rear];
    }
    void printQueue(){ //دالة مهمتها طباعة عناصر الطابور
        if (!isEmpty()){ //بالأستفادة من دالة التحقق من خواء الطابور والتحقق أن الطابور ليس فارغ
        for(size_t i = front; i != rear; i=(i+1)%Max_Length){ 
            cout<< arr[i]<<" "; //طباعة عناصر الطابور
        }
        cout<< arr[rear];
    }
    else 
        cout<<"Empty Queue"; //غير ذلك يعني أن الطابور فارغ عندها يتم اخراج رسالة مفادها أن الطابور فارغ
    }
    
    
};
int main(){

    linkedList l; //تعريف كائن للتعامل مع كلاس القوائم المتصلة
    Stack s; //تعريف كائن للتعامل مع كلاس المكدس
    Queue q; //تعريف كائن للتعامل مع كلاس الطوابير
    int choice;
    int pos;
    int element;
    int Choice;
    string Exit;
    
    cout<< "please choose the num of operation that you want to Run \n 1 for Linked List , 2 for Stack , 3 for Queue : ";
    cin>>Choice; //الطلب من المستخدم أدخال طريقة الأدخال التي يريد أن يتبعها
     
    switch(Choice){ //ادخال خيار المستخدم في للتعامل معه
        case 1: //تعني أن المستخدم فضل أستخدام القوائم المتصلة
        cout<< "Now you using the Linked List,please insert 3 Element "<<endl;
        for (int i = 1; i < 4; i++){
            cout<< "please enter the Element num "<<i<<": ";
            cin>> element; //الطلب من المستخدم أدخال العنصر الذي يود أضافته
            l.insert_Tail(element); //اضافة العنصر في ذيل القائمة
        }
        l.print(); //طباعة العناصر التي تم ادخالها
        do{
            cout << "\nnow To insert more Element|\npress 1 and the Element will be the FIRST one \n";
            cout << "press 2 and the Element will be the LAST one \n";
            cout << "press 3 to insert AT POSITION --Enter the POSITION and then Enter the ELEMENT-- \n";
            cout << "press 4 To REMOVE Element : ";
            try{
                cin>>Choice;
                if (Choice == 1){
                    cout<<"The Element = ";
                    cin>> element;
                    l.insert_Head(element); //في حال اختار المستخدم الرقم" 1" يتم اضافة العنصر الي رأس القائمة
                }
                else if (Choice == 2){
                    cout << "The Element = ";
                    cin >> element;
                    l.insert_Tail(element); //في حال اختار المستخدم الرقم" 2" يتم اضافة العنصر الي ذيل القائمة
                }
                else if (Choice == 3){
                cout  << "The Position = ";
                cin >> pos;
                cout << "The Element = ";
                cin >> element;
                l.insertAtpos(pos,element); //في حال اختار المستخدم الرقم "3" يتم اضافة العنصر الي المكان الذي يحدده المستخدم
            }
            else if (Choice == 4){
                cout << "The Element = ";
                cin >> element;
                l.remove(element); //في حال اختار المستخدم الرقم "4" يتم حذف العنصر من القائمة
                cout << element << " Have been Deleted!\n";
            }
            else
            {
                throw "Something went wrong!"; //القيام بالقاء خطأ متوقع لتجنب توقف البرنامج بسببه
            }
                
        }
        catch(char const*A) //القيام بالتقاط محتوي الخطأ وعمل أستثناء له
        {
            cerr <<"ERROR : "<< A << '\n';
        }
        l.print();
        cout<< "\nDo you want to Exit? | type (Esc) to exit or (Enter) to continue ";
        cin >> Exit; 
    } while (Exit != "Esc"); //شرط مهمته اتاحة القدرة للمستخدم ليخرج من طريقة الأدخال التي أختارها

break;
case 2: //تعني أن المستخدم فضل أستخدام المكدس
    cout << "Now you using Stack,please Push 3 Element " << endl;
    for (int i = 1; i < 4; i++)
    {
        cout << "Enter The Element number " << i << ": ";
        cin >> element;
        s.push(element); //الطلب من المستخدم أدخال العنصر الذي يود أضافته
    }
    s.print(); //طباعة العناصر التي تم ادخالها

    do
    {
        cout << "\nEnter 1 To Push Element on TOP,or Enter  2 To Pop Element from TOP: ";
        try
        {
            cin >> Choice;
            if (Choice == 1) //في حال اختار المستخدم الرقم" 1" يتم اضافة العنصر الي المكدس
            {
                cout << "The Element = ";
                cin >> element;
                s.push(element);
            }
            else if (Choice == 2) //في حال اختار المستخدم الرقم "2" يتم حذف العنصر من المكدس
            {
                s.pop();
            }
            else
            {
                throw "Out of Range!\n"; //القيام بالقاء خطأ متوقع لتجنب توقف البرنامج بسببه
            }            
        }
        catch(char const*A) //القيام بالتقاط محتوي الخطأ وعمل أستثناء له
        {
            cerr << "\nERROR : " << A << '\n';
        }
        s.print();
    cout << "\nDo you want to Exit? type (Esc) to exit or (Enter) to continue : ";
    cin >> Exit;
    } while (Exit != "Esc"); //شرط مهمته اتاحة القدرة للمستخدم ليخرج من طريقة الأدخال التي أختارها

break;

case 3: //تعني أن المستخدم فضل أستخدام الطوابير
    cout << "Now you using the Queue List,please Enter 3 Element " << endl;
    for (int i = 1; i < 4; i++)
    {
        cout << "Enter The Element number " << i << ": ";
        cin >> element;
       q.enQueue(element); //الطلب من المستخدم أدخال العنصر الذي يود أضافته
    }
    q.printQueue(); //طباعة العناصر التي تم ادخالها
    
    do
    {
        cout << "\npress 1 To Enter Element to Queue or 2 To delete Element from Queue: ";
        try
        {
            cin >> Choice;
            if (Choice == 1) //في حال اختار المستخدم الرقم" 1" يتم اضافة العنصر الي الطابور
            {
                cout << "The Element = ";
                cin >> element;
                q.enQueue(element);
            }
            else if (Choice == 2) //في حال اختار المستخدم الرقم "2" يتم حذف العنصر من الطابور
            {
                q.deQueue();
            }
            else
            {
                throw "Out of Range!\n"; //القيام بالقاء خطأ متوقع لتجنب توقف البرنامج بسببه
            }
        }
        catch (char const *A) //القيام بالتقاط محتوي الخطأ وعمل أستثناء له
            {
                cerr << "\nERROR : " << A << '\n';
            }
           q.printQueue();

    cout << "\nDo you want to Exit? type (Esc) to exit or (Enter) to continue : ";
    cin >> Exit;
    } while (Exit != "yes"); //شرط مهمته اتاحة القدرة للمستخدم ليخرج من طريقة الأدخال التي أختارها

break;

default:
    cout << "Something went wrong!"; //لو تم اختيار طريقة ادخال غير متوفرة يتم طباعة رسالة مفادها حدوث خطأ
    break;
}

return 0;
}