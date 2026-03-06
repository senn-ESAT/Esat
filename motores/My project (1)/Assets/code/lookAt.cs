using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class lookAt : MonoBehaviour
{
    public Transform targetTr;
    Vector3 TargetDistance;
    Transform tr;
    // Start is called before the first frame update
    void Start()
    {
        tr = GetComponent<Transform>();
        TargetDistance = tr.position - targetTr.position;
    }

    // Update is called once per frame
    void Update()
    {
        tr.position = targetTr.position + TargetDistance;
        tr.LookAt(targetTr);
    }
}
