#include<stdio.h>
#include<dirent.h>
#include<time.h>
#include<sys/stat.h>


char** getFileList(const char *path, int* fileCount)
{
    int count = 0;
    DIR *dir = NULL;
	struct dirent *ptr = NULL;
    char **fileList = NULL;
    char file[512];
    struct stat fileStat;

    //打开目录
    if ((dir = opendir(path)) == NULL)
	{
		perror("Open dir error..."); //记录日志
	    return NULL;
	}

    //读取目录，统计目录下的文件个数
    while((ptr = readdir(dir)) != NULL)
    {
        //文件绝对路径
        snprintf(file, 512, "%s/%s", path, ptr->d_name); 

        //得到文件信息 
        lstat(file, &fileStat);

        //判断是目录还是文件
        if (!S_ISDIR(fileStat.st_mode))  
        {
            count++;
        }        
    }    

    //关闭目录
    closedir(dir);

    //开辟字符指针数组，用于下一步的开辟容纳文件名字符串的空间
    if( (fileList = (char**)malloc(sizeof(char*) * count)) == NULL)
    {
        perror("first Malloc heap failed!..."); //记录日志
        return NULL;
    }

    //打开目录
    if ((dir = opendir(path)) == NULL)
	{
		perror("Open dir error..."); //记录日志
	    return NULL;
	}

    int i;
    for(i = 0; (ptr = readdir(dir)) != NULL && i < count;)
    {
        if(strlen(ptr->d_name) < 0)
        {
            continue;
        }
        
        //文件绝对路径
        snprintf(file, 512, "%s/%s", path, ptr->d_name); 

        //得到文件信息 
        lstat(file, &fileStat);

        //判断是目录还是文件
        if (!S_ISDIR(fileStat.st_mode))  
        {
            if( (fileList[i] = (char*)malloc(strlen(file) + 1)) == NULL)
            {
                perror("Second Malloc heap failed!..."); //记录日志
                return NULL;
            }

            memset(fileList[i], 0, strlen(file) + 1);
            strcpy(fileList[i], file);
            i++;
        }   
    }

    closedir(dir);

    *fileCount = count;
    return fileList;
        
}


void main(int argc, char *argv[])
{
    const int BUF_SIZE = 1024 ;
    char readBuf[BUF_SIZE];
    
    const char *path = "./Data";
    int fileCount = 0;
    char** fileList = getFileList(path, &fileCount);

    int i = 0;
    for(i = 0; i < fileCount; i++)
    {
        char *file = fileList[i];
        //printf("%s\n", file);

        clock_t start, end;
        start =  clock();

        FILE *fp = fopen(file, "rb");
        int len = 0;
        do
        {
            len = fread(readBuf, 1, BUF_SIZE, fp);
        }while(len != 0);

        fclose(fp);

        end = clock();

        double theTimes = (double)(end - start)/CLOCKS_PER_SEC;
        printf("%s is ready: %f s\n", file, theTimes);
    }
}



