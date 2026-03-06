using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cubeMov : MonoBehaviour
{
    Transform tr;
    public float speed;
    float VerticalValue = 0, HorizontalValue = 0, Rotation = 0;
    Vector3 movement, mov ;

    // Start is called before the first frame update
    void Start()
    {
        tr = GetComponent<Transform>();
    }

    // Update is called once per frame
    void Update()
    {
        VerticalValue = Input.GetAxis("Vertical");
        HorizontalValue = Input.GetAxis("Horizontal");
        Rotation = Input.GetAxis("Mouse X");

        //tr.position += tr.forward * VerticalValue * speed * Time.deltaTime;
        //tr.position += tr.right * HorizontalValue * speed * Time.deltaTime;

        tr.Rotate(Vector3.up * Rotation * Time.deltaTime, Space.Self);

        movement = (tr.forward * VerticalValue) + (tr.right * HorizontalValue);
        mov = movement.normalized;

        tr.position += speed * mov * Time.deltaTime;
    }
}