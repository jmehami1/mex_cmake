mex test.cpp -I/usr/include/eigen3/

point_cloud = [1 2 3; 4 5 6; 7 8 10; 7 8 10];
source_correspondences = [0 0 0; 1 1 1; 2 2 2; 3 3 3];
target_correspondences = [1 1 1; 2 2 2; 3 3 3; 4 4 4];

modified_cloud = test(point_cloud, source_correspondences, target_correspondences);

modified_cloud



