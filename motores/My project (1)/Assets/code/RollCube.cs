using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RollCube : MonoBehaviour
{
    public Transform camTR;
    Rigidbody rb;
    Vector3 inputValue;
    public float force;
    // Start is called before the first frame update
    void Start(){
        rb = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update(){
        inputValue = camTR.forward * Input.GetAxisRaw("Vertical") +
        camTR.right * Input.GetAxisRaw("Horizontal");
        // inputValue.z = Input.GetAxisRaw("Vertical");
        // inputValue.x = Input.GetAxisRaw("Horizontal");
        inputValue.y = 0.0f;
        inputValue = inputValue.normalized;
    }

    void FixedUpdate(){
        rb.AddForce(inputValue * force, ForceMode.Force);
    } 
}
