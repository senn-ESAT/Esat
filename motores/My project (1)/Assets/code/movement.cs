using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class movement : MonoBehaviour
{
  // [SerializzedField] es para que un private sea visible
  public Transform tr;              // posicion de cubo
  public Vector3 targetPosition;    // posicion a la que tiene que ir
  Vector3 positionOrigin;
  Vector3 currentPositionDir;
  public float deltaMovePerFrame;   // distancia movimiento cada frame
  public float radiusOffset;        // area de seguridad para evitar pasarse de posicion

  Vector3 dirMovement;
  Vector3 dirMovementNorm;
  Vector3 despVec;
  // Start is called before the first frame update
  void Start(){
    tr = GetComponent<Transform>();
    positionOrigin = tr.position;    // posicion a la que tiene que ir
    currentPositionDir = targetPosition;
  }



  // Update is called once per frame
  void Update(){

    dirMovement = currentPositionDir - tr.position;
    if (dirMovement.magnitude >= radiusOffset){
      dirMovementNorm = dirMovement.normalized;

      despVec = dirMovementNorm * deltaMovePerFrame * Time.deltaTime;
      tr.position += despVec;
    }
    else {
      if(currentPositionDir == positionOrigin){
        currentPositionDir = targetPosition;
      }
      else{
        currentPositionDir = positionOrigin;
      }
    }
  } 
}