using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Code2 : MonoBehaviour
{
    bool hi;

    // Start is called before the first frame update
    void Start()
    {
        hi = false;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            hi = true;
        }
        if (hi)
        {
            gameObject.
            transform.Translate(0.01f, 0.0f, 0.0f);
            transform.Rotate(1.0f, 0.0f, 1.0f);
            transform.localScale = transform.localScale + new Vector3(0.01f, 0.01f, 0.01f);
            //Debug.Log("position: " + transform.position.y);
        }
    }
}
