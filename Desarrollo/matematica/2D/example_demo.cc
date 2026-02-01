#include <stdio.h>
#include <math.h>

namespace MM {
  // vertor o punto
  struct Vec2 {
    float x, y;
  };

  struct Vec3 {
    float x, y, z;
  };

  struct Vec4 {
    float x, y, z, w;
  };

  struct Mat2 {
    /*
      m = 0 2
          1 3
    */
    float m[4];
  };
  
  struct Mat3 {
    /*
      m = 0 3 6
          1 4 7
          2 5 8
    */
    float m[9];
  };
  
  struct Mat4 {
    /*
      m = 0 4 8  12
          1 5 9  13
          2 6 10 14
          3 7 11 15
    */
    float m[16];
  };
  
  /*
  TO_DO
--- Vect
  Suma de vectores 
  Resta de vectores
  Multiplicación por un escalar 
  División por un escalar
  hipotenusa 
  Algún método de “print”
  Normalizar un vector (dividir por hipotenusa)
  ¿Está normalizado?
  Perpendicular 2D método 1 
  Perpendicular 2D método 2
  ¿Algún método de inicialización?
  */
  
  // ---------- VECTOR ----------

  // - SUM -

  Vec2 sumVec2(Vec2 v1, Vec2 v2){
    Vec2 temp = {{v1.x + v2.x}, {v1.y + v2.y}};
    return temp;
  }

  Vec3 sumVec3(Vec3 v1, Vec3 v2){
    Vec3 temp = {{v1.x + v2.x}, {v1.y + v2.y}, {v1.z + v2.z}};
    return temp;
  }

  Vec4 sumVec4(Vec4 v1, Vec4 v2){
    Vec4 temp = {{v1.x + v2.x}, {v1.y + v2.y}, {v1.z + v2.z}, {v1.w + v2.w}};
    return temp;
  }

  // - SUB -

  Vec2 subVec2(Vec2 v1, Vec2 v2){
    Vec2 temp = {{v1.x - v2.x}, {v1.y - v2.y}};
    return temp;
  }

  Vec3 subVec3(Vec3 v1, Vec3 v2){
    Vec3 temp = {{v1.x - v2.x}, {v1.y - v2.y}, {v1.z - v2.z}};
    return temp;
  }

  Vec4 subVec4(Vec4 v1, Vec4 v2){
    Vec4 temp = {{v1.x - v2.x}, {v1.y - v2.y}, {v1.z - v2.z}, {v1.w - v2.w}};
    return temp;
  }

  // - MULT - 

  Vec2 scaleV2(Vec2 v1, float n){
    Vec2 temp = {{v1.x * n}, {v1.y *n}};
    return temp;
  }

  Vec3 scaleV3(Vec3 v1, float n){
    Vec3 temp = {{v1.x * n}, {v1.y * n}, {v1.z * n}};
    return temp;
  }

  Vec4 scaleV4(Vec4 v1, float n){
    Vec4 temp = {{v1.x * n}, {v1.y * n}, {v1.z * n}, {v1.w * n}};
    return temp;
  }

  // - HIPOTENUSA

  float magnitudeV2(Vec2 v1){
    float temp;
    temp = sqrtf(v1.x * v1.x + v1.y * v1.y);
    return temp;
  }

  float magnitudeV3(Vec3 v1){
    float temp;
    temp = sqrtf(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
    return temp;
  }

  float magnitudeV4(Vec4 v1){
    float temp;
    temp = sqrtf(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z + v1.w * v1.w);
    return temp;
  }

  // - NORM -

  bool isV2Norm (Vec2 v){
    if(v.x > 0.95f && v.x < 1.05f && 
       v.y > 0.95f && v.y < 1.05f){
      return true;
    }
    return false;
  }

  bool isV3Norm (Vec3 v){
    if(v.x > 0.95f && v.x < 1.05f && 
       v.y > 0.95f && v.y < 1.05f &&
       v.z > 0.95f && v.z < 1.05f ){
      return true;
    }
    return false;
  }

  Vec2 normalizeV2 (Vect v1){
    float hipo = magVec2(v);
    Vec2 temp = {{v.x/hipo}, {v.y/hipo}};
    if(temp.x >0.95f && temp.x < 1.05f){

    }
  }

  // - PRINT -

  void Vec2Print(Vec2 v) {
    printf("[X]: %f [Y]: %f\n", v.x, v.y);
  }

  void Vec3Print(Vec3 v) {
    printf("[X]: %f [Y]: %f [Z]: %f\n", v.x, v.y, v.z);
  }

  void Vec4Print(Vec4 v) {
    printf("[X]: %f [Y]: %f [Z]: %f [W]: %f\n", v.x, v.y, v.z, v.w);
  }

  /*
  --- Mat
  Suma de matrices 
  Resta de matrices
  Multiplicación por un escalar 
  División por un escalar
  Multiplicación de matrices 
  Vector por matriz
  Algún método de “print” 
  Iniciar como identidad
  ¿Otro método de inicialización?
  */

  // ---------- MAT ----------
  

  // ---------- COMBO ----------

  Vec2 Vec2MultMat2Vec2(Mat2 mat, Vec2 vec) {
    Vec2 tmp = {
      mat.m[0] * vec.x + mat.m[2] * vec.y,
      mat.m[1] * vec.x + mat.m[3] * vec.y
    };
    return tmp;
  };
  
}

int main(int argc, char** argv) {
  MM::Vec2 v = { 2.0f, 1.0f };
  /*
    m1 = 1.0f 0.0f
         2.0f 1.0f
  */
  MM::Mat2 m1 = { 1.0f, 2.0f, 0.0f, 1.0f };
  /*
    m2 = 2.0f 3.0f
         0.0f 2.0f
  */
  MM::Mat2 m2 = { 2.0f, 0.0f, 3.0f, 2.0f };

  /*
    v1 = m1 * v
     1.0f 0.0f  *  2.0f
     2.0f 1.0f     1.0f
  */
  MM::Vec2 v1 = MM::Vec2MultMat2Vec2(m1, v);
  /*
    v2 = m2 * v
     2.0f 3.0f  *  2.0f
     0.0f 2.0f     1.0f
  */
  MM::Vec2 v2 = MM::Vec2MultMat2Vec2(m2, v);

  MM::Vec2Print(v1);
  MM::Vec2Print(v2);

  return 0;
}
