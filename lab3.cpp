#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>



using namespace std;


class Point{
private:
    int x, y;
public:
    Point(int x, int y) : x(x), y(y){

    }
    int get_x(){
        return x;
    }
    int get_y(){
        return y;
    }
    void set_x(int new_x){
        x = new_x;
    }
    void set_y(int new_y){
        y = new_y;
    }


};



class Object{

private:
    const int id;
    int x_pos, y_pos;
    int speed;
    int r = 0;

    vector<Point> list_point = {};
public:
    Object(int id, int x_pos, int y_pos, int speed) \
    : id(id), x_pos(x_pos), y_pos(y_pos), speed(speed){
        Point one_point(x_pos, y_pos);
        list_point.push_back(one_point);
    }
    int get_id(){
        return id;
    }
    int get_x_pos(){
        return x_pos;
    }
    int get_y_pos(){
        return y_pos;
    }
    void set_x_pos(int new_x_pos){
        x_pos = new_x_pos;
    }
    void set_y_pos(int new_y_pos){
        y_pos = new_y_pos;
    }
    int get_count_point(){
        return list_point.size();
    }
    void randmove(int x_size_map, int y_size_map){
        int rrand = rand() % 4;
        int m_x = 0, m_y = 0;
        if(rrand == 0){
            if(x_pos + speed <= x_size_map)
                m_x = speed;
        }
        else if(rrand == 1){
            if(x_pos - speed >= 0)
                m_x = -1 * speed;       
        }
        else if(rrand == 2){
            if(y_pos + speed <= y_size_map)
                m_y = speed;
        }
        else if(rrand == 3){
            if(y_pos - speed >= 0)
                m_y = -1 * speed;
        }
        
        if(m_x != 0 || m_y != 0){
            cout<<"[]\n";
            y_pos += m_y;
            x_pos += m_y;

            r = r + 1;
            Point *point = new Point(x_pos, y_pos);
            cout<<"old = "<<list_point.size()<<"\n";
            list_point.push_back(*point);
            cout<<"new = "<<list_point.size()<<"\n";
            cout<<"r = "<<r<<endl;
            cout<<"id = "<<id<<endl;

        }
    }
    


};

int create_id_object(vector<Object> list_obj){
    int i;
    int id;
    int proverka;
    while(1){
        proverka = 1;
        id = (rand() % 10000) + 1;
        for(i = 0; i < list_obj.size(); ++i){
            if(id == list_obj[i].get_id()){
                proverka = 0;
                break;
            }
        }
        if(proverka == 1){
            return id;
        }
    }
}

void randmoves(int x_size_map, int y_size_map, vector<Object> list_obj){
    int i;
    for(i = 0; i < list_obj.size(); ++i){
        cout<<"||\n";
        list_obj[i].randmove(x_size_map, y_size_map);
    }
}

int Simulation(int x_size_map, int y_size_map){
    int cn_obj, ch_per;
    int i;
    
    cout<<"Vvedite kolichestvo objectov: ";
    if(!scanf("%d", &cn_obj)){
        cout<<"Error cn_obj: ne chislo\n";
        return -1;
    }
    cout<<"Vvedite kolichestvo peremeshenii: ";
    if(!scanf("%d", &ch_per)){
        cout<<"Error ch_per: ne chislo\n";
        return -1;
    }
    vector<Object> list_obj;
    int id, x_pos, y_pos, speed;
    
    for(i = 0; i < cn_obj; ++i){
        id = create_id_object(list_obj);
        x_pos = rand() % 1000;
        y_pos = rand() % 1000;
        speed = (rand() % 100) + 1;
        Object ptr_pbj(id, x_pos, y_pos, speed);
        list_obj.push_back(ptr_pbj);
        cout<<"Create new obj: id = "<<id<<endl;
        cout<<"pos obj: "<<x_pos<<", "<<y_pos<<endl;
    }
    for(i = 0; i < ch_per; ++i){
        cout<<"i = "<<i<<"\n";
        randmoves(x_size_map, y_size_map, list_obj);
    }
    for(i = 0; i < list_obj.size(); ++i){
        cout<<"id: "<<list_obj[i].get_id()<<endl;
        cout<<"count points: "<<list_obj[i].get_count_point()<<endl;
    }

}




int main(){
    srand(time(NULL));

    Simulation(1000,1000);

    cout << "End\n";
}






