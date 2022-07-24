#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
 
struct Point{
    double x;
    double y;
 
    std::string to_s() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
 
    double distance(Point p) const {
        return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
    }


    // idxp1 and idxp2 are output parameters
// after the function call they will contain
// the indices of the two closest points in vp
// if vp contains two points or more
// (otherwise they will just contain uninitialised values)
 

}; 
void closest_points(const std::vector<Point>& vp, int& idxp1, int& idxp2){
    // TODO:
    // complete this function
    double closest = vp[0].distance(vp[1]);
    idxp1 = 0;
    idxp2 = 1;
    for(int i = 1; i < vp.size(); i++){
        for(int j = i + 1; j < vp.size(); j++){
            if(vp[i].distance(vp[j]) < closest){
                idxp1 = i;
                idxp2 = j;
            }
        }
    }
    // (make use of member function distance)
}
 
int main(){
    std::ifstream infile;
    infile.open("points.txt");
 
    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }
 
    std::vector<Point> points;
    Point tmp;
 
    while(infile >> tmp.x >> tmp.y){
        points.push_back(tmp);
    }
 
    infile.close();
 
    // TODO: 
    // print the content of the vector
    for(int i = 0; i < points.size(); i++){
        std::cout << points[i].to_s() << std::endl;
    }
    // using a loop calling member function to_s 
    // on each element in the vector

    if(points.size() == 0){
        std::cout << "there are no points in the file" << std::endl;
    }
    else if(points.size() == 1){
        std::cout << "there is only one point in the file" << std::endl;
    }
    else{
        int idxp1, idxp2;
        closest_points(points, idxp1, idxp2);
 
        // TODO: 
        std::cout << points[idxp1].to_s() << std::endl << points[idxp2].to_s() << std::endl;
        // print the two points
        // (make use of member function to_s)
      }
        
 
}