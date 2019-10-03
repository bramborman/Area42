using UnityEngine;

public class Fireball : MonoBehaviour
{
    [SerializeField] private new Rigidbody rigidbody = null;
    [SerializeField] private float forceMultiplier = 50f;

    public void Shoot(Vector3 direction)
    {
        rigidbody.AddForce(direction * forceMultiplier, ForceMode.Impulse);
    }
}
