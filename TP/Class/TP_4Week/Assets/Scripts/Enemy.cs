using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    private float z_pos;

    public float eneSpeed;

    // Start is called before the first frame update
    void Start()
    {
        z_pos = 0.0f;
    }

    // Update is called once per frame
    void Update()
    {
        z_pos -= 0.2f;
        transform.Translate(0.0f, 0.0f, z_pos * eneSpeed * Time.deltaTime);

        if (transform.position.z < -10.0f)
        {
            Destroy(gameObject, 0);
        }
    }
}
