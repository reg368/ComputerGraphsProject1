#ifndef OBJLOADER_H
#define OBJLOADER_H
#include <stdio.h>
#include <stdlib.h>
#include <vector>


class ObjLoader
{
    public:
        ObjLoader();
        bool LoadObjFromFile(const char*,std::vector<float>*,std::vector<float>*);

    protected:

    private:
};

#endif // OBJLOADER_H
