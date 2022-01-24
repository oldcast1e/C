#include  <stdio.h>
struct vector
{
    /* data */
    int x,y,z;
};

int main(){
    struct vector vec1,vec2;
    int vec3;
    scanf("%d %d %d",&vec1.x,&vec1.y,&vec1.z);
    scanf("%d %d %d",&vec2.x,&vec2.y,&vec2.z);
    printf("%d %d %d\n",vec1.x*vec2.x,vec1.y*vec2.y,vec1.z*vec2.z);
    vec3 = vec1.x*vec2.x + vec1.y*vec2.y + vec1.z*vec2.z;
    printf("%d",vec3);


}