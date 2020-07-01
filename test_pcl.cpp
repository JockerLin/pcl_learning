//
// Created by pilcq on 2020/6/12.
//

#include <iostream>
#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/console/parse.h>
#include <pcl/filters/filter.h>


int testPcl(){
    std::cout << "Test PCL !" << std::endl;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr (new pcl::PointCloud<pcl::PointXYZRGB>);
    uint8_t r(255), g(15), b(15);
    for (float z(-1.0); z <= 1.0; z += 0.05) {
        for (float angle(0.0); angle <= 360.0; angle += 5.0) {
            pcl::PointXYZRGB point;
            point.x = 0.5 * cosf (pcl::deg2rad(angle));
            point.y = sinf (pcl::deg2rad(angle));
            point.z = z;
            uint32_t rgb = (static_cast<uint32_t>(r) << 16 | static_cast<uint32_t>(g) << 8 | static_cast<uint32_t>(b));
            point.rgb = *reinterpret_cast<float*>(&rgb);
            point_cloud_ptr->points.push_back (point);
        }
        if (z < 0.0) {
            r -= 12;
            g += 12;
        }
        else {
            g -= 12;
            b += 12;
        }
    }

    point_cloud_ptr->width = (int) point_cloud_ptr->points.size ();
    point_cloud_ptr->height = 10;

    pcl::visualization::CloudViewer viewer ("test");
    viewer.showCloud(point_cloud_ptr);
    while (!viewer.wasStopped()){ };
    return 0;
}

int testConst(){
    //    testPcl();

//    const int p = 9;
//    const void * vp = &p;
//
//    const int *ptr;
//    *ptr = 10;
//    const int *ptr;
//    int val = 3;
//    ptr = &val;

//    int num=0;
//    int * const ptr=&num; //const指针必须初始化！且const指针的值不能修改
//    int * t = &num;
//    *t = 12;
//    cout<<*ptr<<endl;

//    const int num=10;
//    const int * ptr=&num;

//    const void * hm = 'jh';
//    const int * ptr;
//    int val = 3;
//    ptr = &val;
//    cout<<*ptr<<endl;
//
//    int *ptr1 = &val;
//    *ptr1=4;
//    cout<<*ptr<<endl;

//    int * const ptr 指针的地址是常量，指针指向的值是变量,const修饰ptr
//    const int * ptr 指针的地址是变量，指针指向的值是常量,const修饰*
    const int num=0;
    int const * ptr=&num; //error! const int* -> int*
    cout<<*ptr<<endl;
    return 0;
}



class Apple{
public:
    static int i;

    Apple(){


    };
};

int Apple::i = 1;

int testStatic(){

    Apple obj1;
    Apple obj2;
    obj1.i = 2;
    obj2.i = 3;

// prints value of i
    cout << obj1.i<<" "<<obj2.i;
    return 0;
}



int main(int argc, char **argv) {
    testStatic();
}