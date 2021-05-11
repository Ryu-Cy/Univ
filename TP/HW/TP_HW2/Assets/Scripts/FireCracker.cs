using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FireCracker : MonoBehaviour
{
    public float speed = 100.0f;
    public float time;
    public bool checkTime;

    public GameObject q;
    public GameObject w;
    public ParticleSystem e;

    // Start is called before the first frame update
    void Start()
    {
        time = 0.0f;
        checkTime = false;
        e.Pause();
        //e.Play();
    }

    // Update is called once per frame
    void Update()
    {
        transform.Translate(new Vector3(0, speed * Time.deltaTime, 0));
        time += Time.deltaTime;
        if (time > 2.0f)
        {
            checkTime = true;
        }
        if (checkTime)
        {
            q.SetActive(false);
            w.SetActive(false);
            e.Play();
        }
        Destroy(gameObject, 3.0f);
    }
}
