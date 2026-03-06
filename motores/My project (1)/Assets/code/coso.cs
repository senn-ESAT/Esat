using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class coso : MonoBehaviour
{
  Rigidbody rb;
  Transform respawn;
  // Start is called before the first frame update
  void Start(){
    rb =  GetComponent<Rigidbody>();
    GameObject temp = GameObject.Find("GameObject"); 
    respawn =  temp.GetComponent<Transform>();
  }

  private void OnCollisionEnter(Collision coll){
    string name = coll.gameObject.name;
    GameObject temp = GameObject.Find(name);
    if(temp.tag == "Player"){
    Transform tr = temp.GetComponent<Transform>();
    Rigidbody rbP = temp.GetComponent<Rigidbody>();
    tr.position = respawn.position;
    rbP.velocity = Vector3.zero;
    rbP.angularVelocity = Vector3.zero; 
    }
  }
}
