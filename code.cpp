            #include<bits/stdc++.h>
            #include "json.hpp"   //for reading JSON data

            using json = nlohmann::json;
            using namespace std;
        json cars_data;
        vector<pair<double, string >> res;
        void get_closest_points(double x, double y){                  //function to get closest vehicles
        priority_queue <pair<double,string>>max_heap;
            for(json::iterator obj = cars_data.begin(); obj != cars_data.end(); obj++){
                json car = *obj;        //dereference the JSON iterator
                string id = car["id"];  //get id of the vehicle
                string x_ = car["x"];   //get x-coordinate of the vehicle
                string y_ = car["y"];   //get y-coordinate of the vehicle
                double x1 = stoi(x_);   // convert string into double
                double y1 = stoi(y_);

                double euclidean_dis = double(sqrt(pow(abs(x1 - x), 2) + pow(abs(y1 - y), 2))); //find euclidean distance of the point from current location
                if(max_heap.size() < 5){
                    max_heap.push({euclidean_dis, id});
                }
                else if(euclidean_dis < max_heap.top().first){           //keep only top 5 closest vehicles in heap
                max_heap.pop();
                max_heap.push({euclidean_dis, id});
                }

        }
        while(!max_heap.empty()){                       //put top 5 closest vehicles in result array
            res.push_back({max_heap.top()});
            max_heap.pop();
        }
        reverse(res.begin(), res.end());

        }
            int main()
            {
            std::ifstream data("dataset.json", std::ifstream::binary);
            data >> cars_data;
            float x,y;
            cout << "Enter your current coordinates"<<"\n";
            cin >> x >> y;
            get_closest_points(x, y);
            for(auto itr : res){
                cout<<"ID of one of the 5 closest vehicles is " << itr.second << " and euclidean distance from current location is " << itr.first << "\n";
            }



            }

