using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Pirate_Ship : MonoBehaviour
{
    public float rotSpeed = 100.0f;
    public bool dir;

    // Start is called before the first frame update
    void Start()
    {
        dir = false;
    }

    // Update is called once per frame
    void Update()
    {
        if (dir)
            transform.Rotate(new Vector3(0, 0, rotSpeed * Time.deltaTime));
        else
            transform.Rotate(new Vector3(0, 0, -rotSpeed * Time.deltaTime));
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Pirate_Ship_Height")
        {
            if (dir)
                dir = false;
            else
                dir = true;
        }
    }
}