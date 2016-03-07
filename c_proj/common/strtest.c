#include<stdio.h>
#include<string.h>

void main()
{
    char input[] = "13693458823|1451528558080|1451528558111|p.l.qq.com/p?oid=55&exp=0&pv_type=0&loid=1&seq=3&index=1&chid=0&channel=100101&loc=QQlive_APPWeb_MB_XXL&appversion=151202&pf=aphone&server_data=&dtype=3&data=AS64N6HIoeOll5WjixZ%2B7x1MJf%2FbEoPTmb4cSNiQPXGIB%2FbOFT4QR2S%2BcPfBGLEOye89ArEbHL0G74flTijQJnjTuSaMjUvk7jFyp1bGZzHA2D9nECSd2Q%2FZsDmVX3EllTrEs0Pjb114IF%2FdUb8k98Ro%2BTqkS6p%2FT4Ga2pBRa3wScCZofooILJpJyPxAsCgW5VBdRwD8wla%2FsAN7UEiRPQleOZLuSp7EkcPT%2FGYCznAoz93LtMbHkOVeQgdek7pGNKLoPrd7vJP2oZwCkttTQ4vfM%2BbRisOsx9uXRnrDODIFLXsJBzzpzyQjl0U1VL1YaCbL7xPWI%2|1|9|872|108462|3|cmnet|866357026773306|103\r\n13693458824|1451528558081|1451528558112|p.l.qq.com/p?oid=55&exp=0&pv_type=0&loid=1&seq=3&index=1&chid=0&channel=100101&loc=QQlive_APPWeb_MB_XXL&appversion=151202&pf=aphone&server_data=&dtype=3&data=AS64N6HIoeOll5WjixZ%2B7x1MJf%2FbEoPTmb4cSNiQPXGIB%2FbOFT4QR2S%2BcPfBGLEOye89ArEbHL0G74flTijQJnjTuSaMjUvk7jFyp1bGZzHA2D9nECSd2Q%2FZsDmVX3EllTrEs0Pjb114IF%2FdUb8k98Ro%2BTqkS6p%2FT4Ga2pBRa3wScCZofooILJpJyPxAsCgW5VBdRwD8wla%2FsAN7UEiR";
    char *p = NULL;

    p = strtok(input, "\r\n");
    if (p)   
    {
        printf("%s\n", p);
    }
}
