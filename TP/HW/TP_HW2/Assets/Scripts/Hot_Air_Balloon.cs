using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Hot_Air_Balloon : MonoBehaviour
{
    public float speed = 100.0f;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (transform.position.y < 10)
        {
            transform.Translate(new Vector3(0, speed * Time.deltaTime, 0));
        }

        if (transform.position.z < 10)
        {
            transform.Translate(new Vector3(0, 0, -speed * Time.deltaTime));
        }
    }
}
