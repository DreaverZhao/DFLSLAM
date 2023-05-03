#include "fbow/fbow.h"
#include "fbow/vocabulary_creator.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    vector<Mat> descriptors;
    //read from command line where to find descriptors
    for(int i = 0; i < argc; i++)
    {
        if(strcmp(argv[i],"-d") == 0)
        {
            string path = argv[i+1];
            //read txt files in directory one by one
            cout << "reading directory " << path << endl;
            vector<String> files;
            cv::glob(path, files);
            for(size_t i = 0; i < files.size(); i++)
            {
                cout << "reading file " << files[i] << endl;
                Mat m;
                //convert txt file to cv mat
                ifstream fin;
                fin.open(files[i]);
                string line;
                while(getline(fin,line))
                {
                    stringstream ss(line);
                    float x;
                    vector<float> v;
                    while(ss >> x)
                        v.push_back(x);
                    Mat row = Mat(v).clone().reshape(1,1);
                    m.push_back(row);
                }
                descriptors.push_back(m);
            }
        }
    }
    if(!descriptors.size())
        cout << "Did not find descriptors. Please use -d option.";

    //训练词点
    //训练词典的参数
    fbow::VocabularyCreator::Params params;
    //fbow::VocabularyCreator::Params params;
    //叶子节点的个数
    params.k = 10;
    //树的高度
    params.L = 5;
    //使用的线程数量
    params.nthreads=1;
    //最大迭代次数
    params.maxIters=0;
    //词典创建工具
    fbow::VocabularyCreator vocabCat;
    //词典
    cout<<"creating vocabulary ... "<<endl;
    fbow::Vocabulary vocab;
    vocabCat.create(vocab,descriptors,"DFLSLAM",params);
    //保存词典
    vocab.saveToFile("filename");
    cout<<"done"<<endl;
    return 0;
}
