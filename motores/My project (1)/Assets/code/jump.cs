using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class jump : MonoBehaviour
{
    Rigidbody rbPlayer;
    Ray ray;
    // Start is called before the first frame update
    void Start()
    {
        rbPlayer = GetComponent<Rigidbody>();
        ray = new Ray(transform.position, transform.forward);
        ray.direction = 
    }

    // Update is called once per frame
    void Update()
    {
        float jump = Input.GetAxisRaw("Jump");
        Vector3 forward = transform.TransformDirection(Vector3.forward) * 10;
        Debug.DrawRay(transform.position, forward, Color.green);

        if (jump != 0) {
            // if ray toca
            Vector3 point = ray.GetPoint(0);
            if(point.y == 0)
                rbPlayer.AddForce(transform.up * 10);

        }
    }
}
