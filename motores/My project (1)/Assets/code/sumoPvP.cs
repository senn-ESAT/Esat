using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class sumoPvP : MonoBehaviour
{
    public Transform camTR;
    Rigidbody rbP1, rbP2;
    Vector3 inputP1, inputP2;
    public float force;
    // Start is called before the first frame update
    void Start(){
        rbP1 = GetComponent<Rigidbody>();
        GameObject temp = GameObject.Find("P2"); 
        rbP2 = temp.GetComponent<Rigidbody>();
    }

    private void OnCollisionEnter(Collision collision){
        //en teoria tendria que empujar para atras pero no lo hace
        rbP1.AddForce(Vector3.right * force);
        rbP2.AddForce(Vector3.right * force);
    }

    // Update is called once per frame
    void Update(){
        inputP1.z = Input.GetAxisRaw("VerticalP1");
        inputP1.x = Input.GetAxisRaw("HorizontalP1");
        inputP1 = inputP1.normalized;

        inputP2.z = Input.GetAxisRaw("VerticalP2");
        inputP2.x = Input.GetAxisRaw("HorizontalP2");
        inputP2 = inputP2.normalized;
    }

    void FixedUpdate(){
        rbP1.AddForce(inputP1 * force, ForceMode.Force);
        rbP2.AddForce(inputP2 * force, ForceMode.Force);
    } 
}
