using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class follow : MonoBehaviour
{
  // [SerializzedField] es para que un private sea visible
  public Transform tr;              // posicion de cubo
  public Transform trObjective;     // posicion de objeto
  public float deltaMovePerFrame;   // distancia movimiento cada frame
  public float radiusOffset;        // area de seguridad para evitar pasarse de posicion

  Vector3 dirMovement;
  Vector3 dirMovementNorm;
  Vector3 despVec;
  // Start is called before the first frame update
  void Start(){
    tr = GetComponent<Transform>();
  }

  // Update is called once per frame
  void Update(){
    GameObject temp = GameObject.Find("Target"); 
    trObjective = temp.GetComponent<Transform>();

    dirMovement = trObjective.position - tr.position;
    if (dirMovement.magnitude >= radiusOffset){
      dirMovementNorm = dirMovement.normalized;

      despVec = dirMovementNorm * deltaMovePerFrame * Time.deltaTime;
      tr.position += despVec;
    }
  } 
}