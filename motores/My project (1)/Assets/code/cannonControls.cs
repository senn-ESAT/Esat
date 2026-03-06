using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cannonControls : MonoBehaviour
{
    Transform trCannon;
    public Transform ballStart;
    public GameObject ballPrefab;
    float Force = 0;
    Vector3 DirDisparo;
    // Start is called before the first frame update
    void Start()
    {
        trCannon = GetComponent<Transform>();
    }

    // Update is called once per frame
    void Update()
    {
        float fire = Input.GetAxisRaw("Jump");
        if (fire == 0)
        {
            // si presionado baja si no va al centro
            float vAngle, hAngle;

            vAngle = 45 - (Input.GetAxisRaw("Vertical") * 45);
            hAngle = Input.GetAxisRaw("Horizontal") * 45;

            Quaternion target = Quaternion.Euler(vAngle, hAngle, 90);

            // Dampen towards the target rotation
            trCannon.rotation = Quaternion.Slerp(trCannon.rotation, target, Time.deltaTime * 1f);
        }
        else {
            Force += 2f;
            if (Force > 1000) { Force = 1000; }
        }

        if (Force > 0 && fire == 0) {
            GameObject spawnBall = Instantiate(ballPrefab, ballStart.position, trCannon.rotation);
            Rigidbody rbBall = spawnBall.GetComponent<Rigidbody>();
            if (Force < 200) { 
            Force = 200;
            }

            rbBall.AddForce(spawnBall.transform.right * Force, ForceMode.Force);
            Force = 0;
        }
    }
}
