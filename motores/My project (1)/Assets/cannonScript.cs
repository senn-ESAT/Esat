using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cannonScript : MonoBehaviour
{
    public Transform trCannon;
    // Start is called before the first frame update
    void Start()
    {
        trCannon = GetComponent<Transform>();
    }

    // Update is called once per frame
    void Update()
    {
        float angle;

        angle = Input.GetAxisRaw("Vertical");

        float tiltAroundX = Input.GetAxis("Vertical") * 60f;

        // Rotate the cube by converting the angles into a quaternion.
        Quaternion target = Quaternion.Euler(0, angle, 0);

        // Dampen towards the target rotation
        trCannon.rotation = Quaternion.Slerp(trCannon.rotation, target, Time.deltaTime * 5f);
    }
}
