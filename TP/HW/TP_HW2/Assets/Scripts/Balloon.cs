using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Balloon : MonoBehaviour
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
        if (transform.localScale.x < 5.0f)
        {
            transform.localScale += new Vector3(speed * 1.5f * Time.deltaTime, speed * 1.5f * Time.deltaTime, speed * 1.5f * Time.deltaTime);
        }
    }
}
